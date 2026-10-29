#!/bin/sh
# Builds agbcc (pret's open-source GCC 2.9 for Thumb) natively and installs it into tools/agbcc/{bin,include,lib}.
# Clones pret/agbcc at a pinned commit into tools/agbcc/src (git-ignored), applies tools/agbcc-tpcs-frame.patch
# (restores -mtpcs-frame / -mtpcs-leaf-frame, which pret removed in d28ac43 and the game was built with),
# builds with the upstream build.sh and checks the backtrace prologue. Why: docs/compiler.md.
# Needs: git, make, a host C compiler, arm-none-eabi-as and arm-none-eabi-ar (Homebrew arm-none-eabi-binutils).
set -e

AGBCC_URL=https://github.com/pret/agbcc
AGBCC_COMMIT=da598c1d918402c42c0c0d7128ba14567f3175e9

REPO=$(cd "$(dirname "$0")/.." && pwd)
DEST=$REPO/tools/agbcc
SRC=$DEST/src
PATCH=$REPO/tools/agbcc-tpcs-frame.patch

for tool in git make cc arm-none-eabi-as arm-none-eabi-ar; do
	command -v $tool >/dev/null 2>&1 || { echo "setup_agbcc: $tool not found in PATH" >&2; exit 1; }
done

if [ ! -d "$SRC/.git" ]; then
	mkdir -p "$DEST"
	git clone "$AGBCC_URL" "$SRC"
fi
if [ "$(git -C "$SRC" rev-parse HEAD)" != "$AGBCC_COMMIT" ]; then
	git -C "$SRC" diff --quiet || { echo "setup_agbcc: $SRC has local changes and is not at $AGBCC_COMMIT" >&2; exit 1; }
	git -C "$SRC" checkout --quiet "$AGBCC_COMMIT"
fi

if git -C "$SRC" apply --reverse --check "$PATCH" 2>/dev/null; then
	echo "setup_agbcc: patch already applied"
else
	git -C "$SRC" apply "$PATCH"
fi

echo "setup_agbcc: building (log: $DEST/build.log)"
(cd "$SRC" && sh build.sh) > "$DEST/build.log" 2>&1 || { tail -20 "$DEST/build.log" >&2; exit 1; }
(cd "$SRC" && sh install.sh "$REPO")

# Smoke test: an empty function must get the game's backtrace frame (docs/rom-survey.md).
TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
echo 'void f(void) { }' > "$TMP/t.c"
"$DEST/bin/old_agbcc" -O2 -mthumb-interwork -mtpcs-frame -mtpcs-leaf-frame "$TMP/t.c" -o "$TMP/t.s"
grep -q 'Backtrace structure created' "$TMP/t.s" || { echo "setup_agbcc: -mtpcs-frame has no effect" >&2; exit 1; }
arm-none-eabi-as -mcpu=arm7tdmi "$TMP/t.s" -o "$TMP/t.o"
echo "setup_agbcc: OK ($DEST/bin: $(ls "$DEST/bin" | tr '\n' ' '))"

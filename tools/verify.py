#!/usr/bin/env python3
"""The phase 3 gate: the built ROM's SHA1 must equal config/usa/baserom.sha1.

    python tools/verify.py [rom]      # default: build/usa/lsw1_usa.gba

Prints VERIFY PASSED and exits 0 only on an exact SHA1 match. On a mismatch it also reports the size and the
first differing offset against the user's dump when that is in extract/ (a hint only; the SHA1 is the verdict).
"""
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import gbarom  # noqa: E402


def first_diff(a: bytes, b: bytes):
    for i in range(0, min(len(a), len(b)), 1 << 16):
        if a[i:i + (1 << 16)] != b[i:i + (1 << 16)]:
            return next(j for j in range(i, i + (1 << 16)) if a[j] != b[j])
    return None if len(a) == len(b) else min(len(a), len(b))


def main():
    rom = Path(sys.argv[1]) if len(sys.argv) > 1 else gbarom.BUILT_ROM
    want = gbarom.target_sha1()
    if not rom.is_file():
        print(f'VERIFY FAILED: {rom} does not exist (run ninja)')
        return 1
    got = gbarom.sha1_of(rom)
    print(f'built   {got}  {rom}')
    print(f'target  {want}  {gbarom.SHA1_FILE.relative_to(gbarom.ROOT)}')
    if got == want:
        print('VERIFY PASSED')
        return 0
    try:
        base = gbarom.find_baserom().read_bytes()
        data = rom.read_bytes()
        d = first_diff(data, base)
        print(f'size {len(data)} vs {len(base)}; first difference at ROM offset 0x{d:X} '
              f'(address 0x{gbarom.ROM_START + d:08X})' if d is not None else 'no byte difference found')
    except SystemExit:
        pass
    print('VERIFY FAILED')
    return 1


if __name__ == '__main__':
    sys.exit(main())

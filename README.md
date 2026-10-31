# LEGO Star Wars: The Video Game (GBA) decompilation

[![Progress](https://bytematch.dev/lasscat/lsw1-gba.svg)](https://bytematch.dev/lasscat/lsw1-gba)

Work in progress: a matching decompilation (the rebuilt ROM must be byte-identical to the original).

The asm build rebuilds the ROM byte for byte; matched functions are C built with a patched agbcc
(`docs/compiler.md`). You need your own legally obtained ROM (see `extract/README.md`).

## Progress

<!-- progress:start -->
`███████░░░░░░░░░░░░░` **32.65%** of the game code matched in C · 1008/1965 game functions

| Part of the code | Functions in C | Bytes in C | Share |
|---|---|---|---|
| Game code | 1008/1965 | 0x1617c/0x43abc | 32.65% |
| Libraries (SDK, libgcc, Krawall) | 0/226 | 0x0/0x6018 | 0.00% |

*Updated 2026-10-31 by `python tools/match.py progress`. A function counts only when it compiles to the exact same bytes and the ROM still rebuilds byte for byte.*
<!-- progress:end -->

```sh
tools/setup_agbcc.sh                 # build the compiler (open source, pinned)
python tools/configure.py && ninja   # rebuild build/usa/lsw1_usa.gba
python tools/match.py verify         # VERIFY PASSED only if the SHA1 equals config/usa/baserom.sha1
```

Layout:

- `config/usa/` ROM SHA1, memory layout, symbols, C source list
- `src/auto/` matched C functions
- `tools/` disassembler, build, judge, match and verify tools
- `docs/` build, compiler, ROM survey, source policy, troubleshooting

Contributions follow `AGENTS.md` and `docs/source-policy.md`: natural C only, verified by the full ROM SHA1.

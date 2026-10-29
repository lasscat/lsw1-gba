# LEGO Star Wars: The Video Game (GBA) decompilation

Work in progress: a matching decompilation (the rebuilt ROM must be byte-identical to the original).

Status: the asm build rebuilds the ROM byte for byte; 2 of 1965 game functions are in C, built with a patched
agbcc (`docs/compiler.md`). You need your own legally obtained ROM (see `extract/README.md`).

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

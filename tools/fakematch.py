"""Fake matches: code that gets the target's bytes without being C that compiles to them.

    from fakematch import fake_match
    why = fake_match(candidate, baseline)   # None when the candidate is plain C

Inline assembly, preprocessor tricks, attributes/sections, assembler directives, machine code written as numbers, or
preprocessor lines the baseline (project.allowed_head(): #include of a repo header) does not have. Comments and
strings are ignored. tools/judge.py refuses such candidates before compiling them.
"""
import re

_STRIP = re.compile(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\\n])*"|\'(?:\\.|[^\'\\\n])*\'', re.S)
FAKE = [
    (re.compile(r"\b(?:__)?asm(?:__)?\b"), "inline assembly (asm)"),
    (re.compile(r"##|\b_Pragma\b"), "preprocessor tricks (## or _Pragma)"),
    (re.compile(r"\b__attribute__\b"), "__attribute__ (sections, naked functions)"),
    (re.compile(r"\.(?:incbin|section|word|byte|long|inst|2byte|4byte)\b"), "assembler directives"),
]
# Thumb code written as numbers: push {.., lr} / pop {.., pc} / bx lr / bl prefix halfwords
OPCODE = re.compile(r"\b0x(?:B5[0-9a-fA-F]{2}|BD[0-9a-fA-F]{2}|4770|F[0-7][0-9a-fA-F]{2})\b", re.I)


def _directives(code: str) -> list:
    return [re.sub(r"\s+", " ", line.strip()) for line in code.split("\n") if line.lstrip().startswith("#")]


def fake_match(code: str, base: str = "") -> str:
    """Why `code` would be a fake match, or None when it is plain C (compared with the baseline `base`)."""
    c, b = _STRIP.sub(" ", code), _STRIP.sub(" ", base or "")
    for pattern, why in FAKE:
        if len(pattern.findall(c)) > len(pattern.findall(b)):
            return why
    if len(OPCODE.findall(c)) - len(OPCODE.findall(b)) >= 3:
        return "machine code written as numbers"
    known = list(_directives(b))
    for d in _directives(c):
        if d in known:
            known.remove(d)
        else:
            return f"new preprocessor line `{d[:60]}`"
    return None

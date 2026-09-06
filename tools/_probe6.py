import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()

C_OLD = """    if (e == -0x17) {
        goto Tiny;
    }
    if (e < -0x17) {
        goto ReturnZero;
    }
"""
C2 = """    if (e + 0x17 == 0) {
        goto Tiny;
    }
    if (e + 0x17 < 0) {
        goto ReturnZero;
    }
"""
assert C_OLD in b

T_OLD = """Tiny:
    frac = sign;
    if ((lo | (hi << 12)) != 0) {
        frac++;
    }
    return frac;
"""
assert T_OLD in b
T1 = """Tiny:
    hi = lo | (hi << 12);
    lo = sign;
    if (hi != 0) {
        lo++;
    }
    return lo;
"""
T2 = """Tiny:
    lo |= hi << 12;
    hi = lo;
    lo = sign;
    if (hi != 0) {
        lo++;
    }
    return lo;
"""

cases = {
    "base": b,
    "C2": b.replace(C_OLD, C2),
    "T1": b.replace(T_OLD, T1),
    "T2": b.replace(T_OLD, T2),
    "C2+T1": b.replace(C_OLD, C2).replace(T_OLD, T1),
    "C2+T2": b.replace(C_OLD, C2).replace(T_OLD, T2),
}
for cc in ("2.0/sp1p5", "dsi/1.6sp2"):
    for k, v in cases.items():
        print(cc, k, "::", run(v, show=2, mwcc=cc).replace("\n", " | ")[:120])

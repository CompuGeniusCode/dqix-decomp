import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()

A_OLD = """    biased = exp << 21;
    if (biased >= 0xffe00000u) {
        goto InfOrNan;
    }
"""
assert A_OLD in b
As = {
    "A1 ge-u": A_OLD,
    "A5 carry": "    biased = exp << 21;\n    if (biased + 0x200000u < 0x200000u) {\n        goto InfOrNan;\n    }\n",
    "A7 carry2": "    biased = (exp << 21) + 0x200000u;\n    if (biased < 0x200000u) {\n        goto InfOrNan;\n    }\n",
    "A2 sge": "    biased = exp << 21;\n    if ((int)biased >= -0x200000) {\n        goto InfOrNan;\n    }\n",
}

B_OLD = """    e = (int)exp - 0x380;
    if (e <= 0) {
        goto Subnormal;
    }
"""
assert B_OLD in b
Bs = {
    "B1 sle": B_OLD,
    "B2 cmp-u": "    e = (int)(exp - 0x380);\n    if (exp <= 0x380) {\n        goto Subnormal;\n    }\n",
    "B7 borrow": "    e = (int)(exp - 0x380);\n    if (exp < 0x380 || e == 0) {\n        goto Subnormal;\n    }\n",
}

C_OLD = """    if (e == -0x17) {
        goto Tiny;
    }
    if (e < -0x17) {
        goto ReturnZero;
    }
"""
assert C_OLD in b
Cs = {
    "C1 direct": C_OLD,
    "C2 plus17": "    if (e + 0x17 == 0) {\n        goto Tiny;\n    }\n    if (e + 0x17 < 0) {\n        goto ReturnZero;\n    }\n",
}

for cc in ("2.0/sp1p5", "dsi/1.6sp2"):
    for an, a in As.items():
        print(cc, an, "::", run(b.replace(A_OLD, a), show=2, mwcc=cc).replace("\n", " | ")[:120])
    for bn, bb in Bs.items():
        print(cc, bn, "::", run(b.replace(B_OLD, bb), show=2, mwcc=cc).replace("\n", " | ")[:120])
    for cn, c in Cs.items():
        print(cc, cn, "::", run(b.replace(C_OLD, c), show=2, mwcc=cc).replace("\n", " | ")[:120])

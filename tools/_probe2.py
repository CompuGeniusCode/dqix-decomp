import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()
A_old = """    biased = exp << 21;
    if (biased >= 0xffe00000u) {
        goto InfOrNan;
    }
    e = (int)exp - 0x380;
    if (e <= 0) {
        goto Subnormal;
    }
"""
assert A_old in b

As = {
    "A1": "    biased = exp << 21;\n    if (biased >= 0xffe00000u) {\n        goto InfOrNan;\n    }\n",
    "A2": "    if ((int)(exp << 21) >= -0x200000) {\n        goto InfOrNan;\n    }\n",
    "A4": "    biased = exp << 21;\n    if ((int)biased >= -0x200000) {\n        goto InfOrNan;\n    }\n",
    "A5": "    if ((exp << 21) + 0x200000u < 0x200000u) {\n        goto InfOrNan;\n    }\n",
    "A6": "    biased = exp << 21;\n    if (0xffe00000u <= biased) {\n        goto InfOrNan;\n    }\n",
}
Bs = {
    "B1": "    e = (int)exp - 0x380;\n    if (e <= 0) {\n        goto Subnormal;\n    }\n",
    "B2": "    e = (int)(exp - 0x380);\n    if (exp <= 0x380) {\n        goto Subnormal;\n    }\n",
    "B3": "    exp -= 0x380;\n    e = (int)exp;\n    if (e <= 0) {\n        goto Subnormal;\n    }\n",
    "B5": "    e = (int)exp - 0x380;\n    if (e < 1) {\n        goto Subnormal;\n    }\n",
    "B6": "    e = (int)exp - 0x380;\n    if (!(e > 0)) {\n        goto Subnormal;\n    }\n",
}

for an, a in As.items():
    for bn, bb in Bs.items():
        out = run(b.replace(A_old, a + bb), show=2)
        line = out.replace("\n", " | ")
        print(an, bn, line[:150])

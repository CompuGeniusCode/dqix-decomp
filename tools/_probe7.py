import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()

MASK_OLD = "    unsigned int exp = (hi >> 20) & ~0x800u;"
assert MASK_OLD in b
A_OLD = """    biased = (exp << 21) + 0x200000u;
    if (biased < 0x200000u) {
        goto InfOrNan;
    }
"""
assert A_OLD in b
B_OLD = """    e = (int)exp - 0x380;
    if (e <= 0) {
        goto Subnormal;
    }
"""
assert B_OLD in b

variants = {
    "V0 base": b,
    "V1 mask7ff": b.replace(MASK_OLD, "    unsigned int exp = (hi >> 20) & 0x7ff;"),
    "V2 mask7ff+eq": b.replace(MASK_OLD, "    unsigned int exp = (hi >> 20) & 0x7ff;")
                      .replace(A_OLD, "    if (exp == 0x7ff) {\n        goto InfOrNan;\n    }\n"),
    "V3 mask7ff+ge": b.replace(MASK_OLD, "    unsigned int exp = (hi >> 20) & 0x7ff;")
                      .replace(A_OLD, "    biased = exp << 21;\n    if (biased >= 0xffe00000u) {\n        goto InfOrNan;\n    }\n"),
    "V4 Bexp-le": b.replace(B_OLD, "    e = (int)(exp - 0x380);\n    if (exp <= 0x380u) {\n        goto Subnormal;\n    }\n"),
    "V5 Bborrow": b.replace(B_OLD, "    e = (int)(exp - 0x380);\n    if ((unsigned int)e > exp || e == 0) {\n        goto Subnormal;\n    }\n"),
    "V6 prop-off": b.replace("// KEEP-NAME", "#pragma opt_propagation off\n\n// KEEP-NAME")
                    .replace(A_OLD, "    biased = exp << 21;\n    if (biased >= 0xffe00000u) {\n        goto InfOrNan;\n    }\n"),
}
for cc in ("2.0/sp1p5", "dsi/1.6sp2"):
    for k, v in variants.items():
        print(cc, k, "::", run(v, show=2, mwcc=cc).replace("\n", " | ")[:120])

import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()
A_OLD = """    biased = (exp << 21) + 0x200000u;
    if (biased < 0x200000u) {
        goto InfOrNan;
    }
"""
assert A_OLD in b


def A(body):
    return b.replace(A_OLD, body)


variants = {
    "W0 base": b,
    "W1 mul": A("    biased = exp * 0x200000u;\n    if (biased >= 0xffe00000u) {\n        goto InfOrNan;\n    }\n"),
    "W2 mul-neg": A("    biased = exp * 0x200000u;\n    if ((int)biased >= -0x200000) {\n        goto InfOrNan;\n    }\n"),
    "W3 gt": A("    biased = exp << 21;\n    if (biased > 0xffdfffffu) {\n        goto InfOrNan;\n    }\n"),
    "W4 not-lt": A("    biased = exp << 21;\n    if (!(biased < 0xffe00000u)) {\n        goto InfOrNan;\n    }\n"),
    "W5 shl-add-cmn": A("    biased = exp << 21;\n    if (biased + 0x200000u < biased) {\n        goto InfOrNan;\n    }\n"),
    "W6 mul-carry": A("    biased = exp * 0x200000u + 0x200000u;\n    if (biased < 0x200000u) {\n        goto InfOrNan;\n    }\n"),
}
for cc in ("2.0/sp1p5", "dsi/1.6sp2"):
    for k, v in variants.items():
        print(cc, k, "::", run(v, show=2, mwcc=cc).replace("\n", " | ")[:120])

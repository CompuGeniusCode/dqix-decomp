import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()
A_OLD = """    biased = (exp << 21) + 0x200000u;
    if (biased < 0x200000u) {
        goto InfOrNan;
    }
"""
W3 = "    biased = exp << 21;\n    if (biased > 0xffdfffffu) {\n        goto InfOrNan;\n    }\n"
print(run(b.replace(A_OLD, W3), show=14, mwcc="2.0/sp1p5"))

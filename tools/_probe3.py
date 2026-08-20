import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()

TAIL1_OLD = """    res = sign | ((hi << 12) >> 9);
    res |= lo >> 29;
    rem = lo << 3;
    res |= (unsigned int)e << 23;
    if (rem == 0) {
        return res;
    }
    if ((rem & 0x80000000) == 0) {
        return res;
    }
    rem <<= 1;
    if (rem == 0) {
        rem = res & 1;
    }
    if (rem != 0) {
        res++;
    }
    return res;
"""
assert TAIL1_OLD in b

TAIL1_NEW = """    frac = sign | ((hi << 12) >> 9);
    frac |= lo >> 29;
    hi = lo << 3;
    lo = frac | ((unsigned int)e << 23);
    if (hi == 0) {
        return lo;
    }
    if ((hi & 0x80000000) == 0) {
        return lo;
    }
    hi <<= 1;
    if (hi == 0) {
        hi = lo & 1;
    }
    if (hi != 0) {
        lo++;
    }
    return lo;
"""

TAIL2_OLD = """    frac = ((hi << 11) | 0x80000000u) >> 8;
    frac |= lo >> 29;
    shift = (unsigned int)(1 - e);
    rem = lo << 3;
    res = sign | (frac >> shift);
    frac <<= 32 - shift;
    if (rem != 0) {
        frac |= 1;
    }
    if (frac == 0) {
        return res;
    }
    if ((frac & 0x80000000) == 0) {
        return res;
    }
    frac <<= 1;
    if (frac == 0) {
        frac = res & 1;
    }
    if (frac != 0) {
        res++;
    }
    return res;
"""
assert TAIL2_OLD in b

TAIL2_NEW = """    frac = ((hi << 11) | 0x80000000u) >> 8;
    frac |= lo >> 29;
    shift = (unsigned int)(1 - e);
    rem = lo << 3;
    res = sign | (frac >> shift);
    frac <<= 32 - shift;
    if (rem != 0) {
        frac |= 1;
    }
    rem = frac;
    if (rem == 0) {
        return res;
    }
    if ((rem & 0x80000000) == 0) {
        return res;
    }
    rem <<= 1;
    if (rem == 0) {
        rem = res & 1;
    }
    if (rem != 0) {
        res++;
    }
    return res;
"""

TAIL2_NEW2 = TAIL2_NEW.replace("    rem = lo << 3;", "    hi = lo << 3;")
TAIL2_NEW2 = TAIL2_NEW2.replace("if (rem != 0) {\n        frac |= 1;", "if (hi != 0) {\n        frac |= 1;")
TAIL2_NEW2 = TAIL2_NEW2.replace("    rem = frac;", "    hi = frac;")
TAIL2_NEW2 = TAIL2_NEW2.replace("res = sign | (frac >> shift);", "lo = sign | (frac >> shift);")
TAIL2_NEW2 = TAIL2_NEW2.replace("return res;", "return lo;")
TAIL2_NEW2 = TAIL2_NEW2.replace("if (rem == 0) {\n        return lo;", "if (hi == 0) {\n        return lo;")
TAIL2_NEW2 = TAIL2_NEW2.replace("if ((rem & 0x80000000) == 0) {", "if ((hi & 0x80000000) == 0) {")
TAIL2_NEW2 = TAIL2_NEW2.replace("    rem <<= 1;", "    hi <<= 1;")
TAIL2_NEW2 = TAIL2_NEW2.replace("if (rem == 0) {\n        rem = res & 1;", "if (hi == 0) {\n        hi = lo & 1;")
TAIL2_NEW2 = TAIL2_NEW2.replace("if (rem != 0) {\n        res++;", "if (hi != 0) {\n        lo++;")

cases = {
    "T0 base": b,
    "T1 tail1-param": b.replace(TAIL1_OLD, TAIL1_NEW),
    "T2 tail2-remcopy": b.replace(TAIL2_OLD, TAIL2_NEW),
    "T3 both": b.replace(TAIL1_OLD, TAIL1_NEW).replace(TAIL2_OLD, TAIL2_NEW),
    "T4 all-param": b.replace(TAIL1_OLD, TAIL1_NEW).replace(TAIL2_OLD, TAIL2_NEW2),
}
for k, v in cases.items():
    print(k, "::", run(v, show=2).replace("\n", " | ")[:150])

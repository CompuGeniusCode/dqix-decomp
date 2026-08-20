import sys
sys.path.insert(0, "tools")
from _exp0200ae40 import run, base_text

b = base_text()

INF_OLD = """InfOrNan:
    if ((lo | (hi << 12)) != 0) {
        return 0x7fffffff;
    }
    return sign | 0x7f800000;
"""
INF_GOTO = """InfOrNan:
    if ((lo | (hi << 12)) != 0) {
        goto NotANumber;
    }
    return sign | 0x7f800000;

NotANumber:
    return 0x7fffffff;
"""
assert INF_OLD in b

ROUND1_OLD = """    hi <<= 1;
    if (hi == 0) {
        hi = lo & 1;
    }
    if (hi != 0) {
        lo++;
    }
    return lo;

InfOrNan:"""
ROUND1_OR = """    hi <<= 1;
    if (hi != 0 || (lo & 1) != 0) {
        lo++;
    }
    return lo;

InfOrNan:"""
assert ROUND1_OLD in b

ZERO_OLD = """ZeroExponent:
    if ((lo | (hi << 12)) != 0) {
        goto ReturnZero;
    }
    return sign;
"""
ZERO_FRAC = """ZeroExponent:
    if ((lo | (hi << 12)) != 0) {
        goto ReturnZero;
    }
    frac = sign;
    return frac;
"""
assert ZERO_OLD in b

cases = {
    "P0 base": b,
    "P1 inf-goto": b.replace(INF_OLD, INF_GOTO),
    "P2 round-or": b.replace(ROUND1_OLD, ROUND1_OR),
    "P3 zero-frac": b.replace(ZERO_OLD, ZERO_FRAC),
    "P4 inf+round": b.replace(INF_OLD, INF_GOTO).replace(ROUND1_OLD, ROUND1_OR),
    "P5 all": b.replace(INF_OLD, INF_GOTO).replace(ROUND1_OLD, ROUND1_OR).replace(ZERO_OLD, ZERO_FRAC),
}
for k, v in cases.items():
    print(k, "::", run(v, show=2).replace("\n", " | ")[:130])

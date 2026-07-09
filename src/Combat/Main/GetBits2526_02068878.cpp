#include <globaldefs.h>

struct Inner_02068878 {
    char pad0[8];
    unsigned int field8_lo : 24;
    unsigned int bits2526 : 2;
    unsigned int field8_hi : 6;
};

struct Outer_02068878 {
    struct Inner_02068878* inner;
};

// USA: func_02068878
ARM int GetBits2526_02068878(int unused, struct Outer_02068878* p) {
    struct Inner_02068878* q = p->inner;
    return q != 0 ? q->bits2526 : 0;
}

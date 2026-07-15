#include <globaldefs.h>

struct ThreeShorts021ded84 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

// USA: func_ov025_021ded84
ARM void CopyThreeShorts021ded84(struct ThreeShorts021ded84* dst, struct ThreeShorts021ded84* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
}

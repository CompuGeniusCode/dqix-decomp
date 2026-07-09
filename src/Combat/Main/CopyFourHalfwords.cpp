#include <globaldefs.h>

struct FourHalfwords02033f7c {
    unsigned short f0;
    unsigned short f2;
    unsigned short f4;
    unsigned short f6;
};

// USA: func_02033f7c
ARM void CopyFourHalfwords(struct FourHalfwords02033f7c* dst, struct FourHalfwords02033f7c* src) {
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f6 = src->f6;
}

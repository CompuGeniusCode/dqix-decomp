#include <globaldefs.h>

struct SmallRecord020643e0 {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020643e0
ARM void CopyHalfwordAndTwoBytes(struct SmallRecord020643e0* dst, struct SmallRecord020643e0* src) {
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
}

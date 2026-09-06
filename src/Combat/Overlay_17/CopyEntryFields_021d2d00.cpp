#include <globaldefs.h>

struct Entry021d2d00 {
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    signed char f3;
    unsigned char f4;
    unsigned char f5;
    unsigned char f6;
    signed char f7;
    unsigned short f8;
    unsigned short fa;
    unsigned short fc;
    signed char fe;
};

// USA: func_ov017_021d2d00  (semantic: CopyEntryFields_021d2d00)
extern "C" ARM void func_ov017_021d2d00(Entry021d2d00* dst, Entry021d2d00* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
    dst->f4 = src->f4;
    dst->f5 = src->f5;
    dst->f6 = src->f6;
    dst->f7 = src->f7;
    dst->f8 = src->f8;
    dst->fa = src->fa;
    dst->fc = src->fc;
    dst->fe = src->fe;
}

#include <globaldefs.h>

struct Mid02165f90 { char v[8]; };

struct Entry02165f90 {
    unsigned short a;
    Mid02165f90 mid1;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    Mid02165f90 mid2;
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
};

// USA: func_ov000_02165f90  (semantic: CopyEntry02165f90)
extern "C" ARM void func_ov000_02165f90(struct Entry02165f90* dst, struct Entry02165f90* src) {
    dst->a = src->a;
    dst->mid1 = src->mid1;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->mid2 = src->mid2;
    dst->c1 = src->c1;
    dst->c2 = src->c2;
    dst->c3 = src->c3;
}

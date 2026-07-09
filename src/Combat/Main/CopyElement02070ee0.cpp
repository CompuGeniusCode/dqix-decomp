#include <globaldefs.h>

struct Arr6_02070ee0 {
    unsigned short v[6];
};

struct Block22_02070ee0 {
    unsigned int v[22];
};

struct Element02070ee0 {
    unsigned short f00;
    unsigned char f02;
    unsigned char f03;
    unsigned short f04;
    unsigned short f06;
    unsigned int f08;
    unsigned short f0c;
    unsigned int f10;
    unsigned int f14;
    struct Arr6_02070ee0 f18;
    unsigned int f24;
    unsigned char f28;
    unsigned char f29;
    unsigned short f2a;
    struct Block22_02070ee0 f2c;
};

// USA: func_02070ee0
ARM struct Element02070ee0 *CopyElement02070ee0(struct Element02070ee0 *dst, struct Element02070ee0 *src) {
    dst->f00 = src->f00;
    dst->f02 = src->f02;
    dst->f03 = src->f03;
    dst->f04 = src->f04;
    dst->f06 = src->f06;
    dst->f08 = src->f08;
    dst->f0c = src->f0c;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->f29 = src->f29;
    dst->f2a = src->f2a;
    dst->f2c = src->f2c;
    return dst;
}

#include <globaldefs.h>

struct Src020795e8 {
    unsigned short pad0;
    unsigned char b2;
    signed char b3;
    unsigned int f0 : 3;
    unsigned int f1 : 3;
    unsigned int f2 : 3;
    unsigned int f3 : 3;
    unsigned int f4 : 3;
};

struct Dst020795e8 {
    unsigned char pad[0x138];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char pad2[3];
    int w140;
    int w144;
};

// USA: func_020795e8
ARM void CopyBitFields020795e8(struct Dst020795e8* dst, struct Src020795e8* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
    dst->f4 = src->f4;
    dst->w140 = src->b2;
    dst->w144 = src->b3;
}

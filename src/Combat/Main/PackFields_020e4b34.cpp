#include <globaldefs.h>
#include "std_library_functions.h"

struct PackedFields_020e4b34 {
    unsigned int p0 : 6;
    unsigned int p1 : 6;
    unsigned int p2 : 6;
    unsigned int p3 : 6;
    unsigned int p4 : 2;
    unsigned int p5 : 1;
    unsigned int p6 : 1;
    unsigned int p7 : 1;
    unsigned int pad0 : 1;
    unsigned int p8 : 1;
    unsigned int pad1 : 1;
};

struct Dest_020e4b34 {
    int f0;
    int f4;
    union {
        unsigned int raw;
        PackedFields_020e4b34 bits;
    } f8;
};

// USA: func_020e4b34  (semantic: PackFields_020e4b34)
extern "C" ARM void func_020e4b34(Dest_020e4b34* dst, int a1, int a2, unsigned int a3,
        unsigned char b0, unsigned char b1, unsigned char b2, unsigned char b3,
        unsigned char b4, unsigned char b5, unsigned char b6, unsigned char b7) {
    memset(dst, 0, 0xc);
    dst->f0 = a1;
    dst->f4 = a2;
    dst->f8.bits.p0 = a3;
    dst->f8.bits.p1 = b0;
    dst->f8.bits.p2 = b1;
    dst->f8.bits.p3 = b2;
    dst->f8.bits.p4 = b3;
    dst->f8.bits.p5 = b4;
    dst->f8.bits.p6 = b5;
    dst->f8.bits.p7 = b6;
    dst->f8.bits.p8 = b7;
}

#include <globaldefs.h>

struct Src_021f8198 { int f0; int f4; };
struct Dst_021f8198 {
    unsigned char pad0[0xcc];
    unsigned short fcc;
    unsigned short fce;
    unsigned char pad1[0x100 - 0xd0];
    unsigned short f100;
    unsigned short f102;
};

// USA: func_ov023_021f8198
ARM void ConvertFixedPoint_021f8198(struct Dst_021f8198* a, struct Src_021f8198* b) {
    a->f100 = (unsigned short)((float)b->f0 / 4096.0f);
    a->f102 = (unsigned short)((float)b->f4 / 4096.0f);
    unsigned short t102 = a->f102;
    unsigned short t100 = a->f100;
    a->fcc = t100;
    a->fce = t102;
}

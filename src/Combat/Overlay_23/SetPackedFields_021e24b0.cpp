#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void*, int);

struct Obj021e24b0 {
    char pad0[3];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    char pad1[8];
    int field0xc;
    unsigned char nibbleLow : 4;
    unsigned char bit4 : 1;
    unsigned char bit5 : 1;
    unsigned char bit6 : 1;
    unsigned char bit7 : 1;
};

// USA: func_ov023_021e24b0
ARM void SetPackedFields_021e24b0(void* obj, int val, int f0xc, unsigned char nibbleD, unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8, unsigned char p9) {
    Obj021e24b0* e = (Obj021e24b0*)func_ov023_021e2418(obj, val);
    if (!e) return;
    e->field0xc = f0xc;
    e->lowNibble = nibbleD;
    e->highNibble = p5;
    e->bit4 = p6;
    e->nibbleLow = p7;
    e->bit5 = p8;
    e->bit6 = p9;
}

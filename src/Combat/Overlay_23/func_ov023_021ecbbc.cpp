#include <globaldefs.h>

struct Obj021ecbbc {
    char pad0[0x433];
    unsigned char f433;
    char pad1[0x438 - 0x434];
    unsigned short f438;
    char pad2[0x43c - 0x43a];
    unsigned char f43c;
};

// USA: func_ov023_021ecbbc
extern "C" ARM void func_ov023_021ecbbc(Obj021ecbbc* obj) {
    obj->f438 &= ~0x100;
    obj->f438 |= 0x40;
    obj->f43c = 0;
    obj->f433 = 0;
}

#include <globaldefs.h>

int TestFlag0SetAndFlag1Clear(unsigned short* obj, int mask);
extern "C" int func_ov023_021e29d0(void* a);

extern unsigned short data_02114e30;

struct Obj021e3e98 {
    void* f0;
    char pad4[0xd4 - 4];
    char fd4[1];
    char pad4e4[0x4e4 - 0xd5];
    unsigned char f4e4;
    char pad4e6[1];
    unsigned char f4e6;
    unsigned char f4e7;
    char pad634[0x634 - 0x4e8];
    unsigned short f634;
};

// USA: func_ov023_021e3e98  (semantic: UpdateFlagsAndByte4e6_021e3e98)
extern "C" ARM void func_ov023_021e3e98(struct Obj021e3e98* obj) {
    int cond = (func_ov023_021e29d0(&obj->fd4) == 0x1f);
    if (cond) {
        obj->f634 |= 0x800;
    }

    if (obj->f0 != 0 && (*(int*)((char*)obj->f0 + 0x3dcc) & 0x400) == 0) {
        return;
    }

    if (TestFlag0SetAndFlag1Clear(&data_02114e30, 2) != 0) {
        cond = 1;
    }
    if (!cond) {
        return;
    }

    obj->f634 |= 0x800;
    signed char tmp = *(signed char*)((char*)obj + 0x4e6);
    obj->f4e7 = tmp;
    obj->f4e6 = 1;
    obj->f4e4 = 0;
}

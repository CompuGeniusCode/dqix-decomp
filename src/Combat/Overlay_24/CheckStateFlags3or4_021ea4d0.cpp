#include <globaldefs.h>

struct CheckStruct_021ea4d0 { int pad0[5]; unsigned int f14; int pad1[1]; unsigned int f1c; };

// USA: func_ov024_021ea4d0
ARM int CheckStateFlags3or4_021ea4d0(int a0, struct CheckStruct_021ea4d0* obj) {
    unsigned int t = obj->f14 >> 0x1c;
    if (t != 4 && t != 3) goto ret0;
    {
        unsigned int v = obj->f1c;
        v = (v << 0xd) >> 0x1b;
        if (v == 0) return 1;
    }
ret0:
    return 0;
}

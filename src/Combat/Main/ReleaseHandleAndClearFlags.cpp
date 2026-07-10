#include <globaldefs.h>

extern "C" void func_020301c8(int, int);
int GetData02104304Field4();

struct Obj020941b0 {
    char pad0[0x340];
    int handle;
    char pad1[0x3c8 - 0x344];
    unsigned char flags3c8;
    char pad2[0x3cd - 0x3c9];
    unsigned char nibbleLo : 4;
    unsigned char nibbleHi : 4;
};

// USA: func_020941b0
ARM void ReleaseHandleAndClearFlags(struct Obj020941b0* p) {
    int x = GetData02104304Field4();
    if (p->handle >= 0) {
        func_020301c8(x, p->handle);
        p->handle = -1;
    }
    p->flags3c8 &= ~0x7f;
    p->nibbleLo = 0;
    ((unsigned char*)p)[0x3cd] |= 8;
}

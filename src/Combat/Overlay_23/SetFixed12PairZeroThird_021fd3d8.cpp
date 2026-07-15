#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);

struct Triple_021fd3d8 { unsigned int v[3]; };

// USA: func_ov023_021fd3d8
ARM void SetFixed12PairZeroThird_021fd3d8(void* dst, void* src) {
    struct Triple_021fd3d8 t;
    func_0200f374(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x22) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x24) << 0xc;
    *(struct Triple_021fd3d8*)dst = t;
}

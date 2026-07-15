#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);

struct Triple_021f8b30 { unsigned int v[3]; };

// USA: func_ov023_021f8b30
ARM void SetFixed12PairZeroThird_021f8b30(void* dst, void* src) {
    struct Triple_021f8b30 t;
    func_0200f374(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x3a) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x3c) << 0xc;
    *(struct Triple_021f8b30*)dst = t;
}

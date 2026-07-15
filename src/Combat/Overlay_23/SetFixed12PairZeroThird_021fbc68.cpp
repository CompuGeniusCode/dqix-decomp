#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);

struct Triple_021fbc68 { unsigned int v[3]; };

// USA: func_ov023_021fbc68
ARM void SetFixed12PairZeroThird_021fbc68(void* dst, void* src) {
    struct Triple_021fbc68 t;
    func_0200f374(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x32) << 0xc;
    t.v[1] = *(unsigned short*)((char*)src + 0x34) << 0xc;
    *(struct Triple_021fbc68*)dst = t;
}

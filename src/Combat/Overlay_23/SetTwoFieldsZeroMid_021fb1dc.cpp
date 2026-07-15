#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);

struct Triple_021fb1dc {
    unsigned int v[3];
};

// USA: func_ov023_021fb1dc
ARM void SetTwoFieldsZeroMid_021fb1dc(void* dst, void* src) {
    struct Triple_021fb1dc t;
    func_0200f374(&t, 0xc);
    t.v[0] = *(unsigned int*)((char*)src + 0x28);
    t.v[2] = *(unsigned int*)((char*)src + 0x2c);
    *(struct Triple_021fb1dc*)dst = t;
}

#include <globaldefs.h>

extern "C" void __clear(void* buf, int n);

struct Triple_021fb4dc { unsigned int v[3]; };

// USA: func_ov023_021fb4dc
ARM void SetFixed12PairZeroMid_021fb4dc(void* dst, void* src) {
    struct Triple_021fb4dc t;
    __clear(&t, 0xc);
    t.v[0] = *(unsigned short*)((char*)src + 0x28) << 0xc;
    t.v[2] = *(unsigned short*)((char*)src + 0x2a) << 0xc;
    *(struct Triple_021fb4dc*)dst = t;
}

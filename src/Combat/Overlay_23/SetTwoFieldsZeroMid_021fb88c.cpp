#include <globaldefs.h>

extern "C" void func_0200f374(void* buf, int n);

struct Triple_021fb88c {
    unsigned int v[3];
};

// USA: func_ov023_021fb88c
ARM void SetTwoFieldsZeroMid_021fb88c(void* dst, void* src) {
    struct Triple_021fb88c t;
    func_0200f374(&t, 0xc);
    t.v[0] = *(unsigned int*)((char*)src + 0xa8);
    t.v[2] = *(unsigned int*)((char*)src + 0xac);
    *(struct Triple_021fb88c*)dst = t;
}

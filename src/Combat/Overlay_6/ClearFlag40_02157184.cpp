#include <globaldefs.h>

extern "C" void func_ov023_021dcd90(void* p, int x);
extern "C" void func_ov006_02155508(void* s);

struct ClearFlag40_02157184Struct {
    unsigned char pad[0xae2];
    unsigned short flags;
};

// USA: func_ov006_02157184
ARM void ClearFlag40_02157184(struct ClearFlag40_02157184Struct* s) {
    s->flags &= ~0x40;
    func_ov023_021dcd90((char*)s + 0x2e4 + 0x800, 0);
    func_ov006_02155508(s);
}

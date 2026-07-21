#include <globaldefs.h>

struct Entity02225e1c { unsigned char pad[0x34]; int* field34; };

struct Pair02225e1c { int off; volatile int hi; };

extern Entity02225e1c* data_ov031_02250c00;
extern "C" void func_ov031_022266b0(int a, int b);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225ea0(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225e1c  (semantic: CheckThreshold91ThenChain_02225e1c)
extern "C" ARM void func_ov031_02225e1c(void* obj) {
    Entity02225e1c* e = data_ov031_02250c00;
    int val = *e->field34;
    struct Pair02225e1c p;
    p.hi = (unsigned int)(val & 0x1ff0000) >> 0x10;
    p.off = (val & 0xff) - 0xc;
    if (p.off > 0x91) {
        func_ov031_022266b0(3, p.off);
        return;
    }
    func_ov031_022266b0(3, 0x91);
    func_ov031_022266b0(4, 0xc0);
    func_ov031_0223e2b8(obj, (int)func_ov031_02225ea0);
}

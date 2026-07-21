#include <globaldefs.h>

struct Entity02225c90 { unsigned char pad[0x10]; int* field10; };

struct Pair02225c90 { int off; volatile int hi; };

extern Entity02225c90* data_ov031_02250c00;
extern "C" void func_ov031_022266b0(int a, int b);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225d14(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225c90  (semantic: CheckThreshold4cThenChain_02225c90)
extern "C" ARM void func_ov031_02225c90(void* obj) {
    Entity02225c90* e = data_ov031_02250c00;
    int val = *e->field10;
    struct Pair02225c90 p;
    p.hi = (unsigned int)(val & 0x1ff0000) >> 0x10;
    p.off = (val & 0xff) - 0xc;
    if (p.off > 0x4c) {
        func_ov031_022266b0(0, p.off);
        return;
    }
    func_ov031_022266b0(0, 0x4c);
    func_ov031_022266b0(1, 0xc0);
    func_ov031_0223e2b8(obj, (int)func_ov031_02225d14);
}

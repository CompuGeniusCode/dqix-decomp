#include <globaldefs.h>

struct Entity02225d14 { unsigned char pad[0x1c]; int* field1c; };

struct Pair02225d14 { int off; volatile int hi; };

extern Entity02225d14* data_ov031_02250c00;
extern "C" void func_ov031_022266b0(int a, int b);
extern "C" void func_ov031_0223e2b8(void* obj, int v);
extern "C" void func_ov031_02225d98(void* obj);

#pragma optimize_for_size off
// USA: func_ov031_02225d14  (semantic: CheckThreshold63ThenChain_02225d14)
extern "C" ARM void func_ov031_02225d14(void* obj) {
    Entity02225d14* e = data_ov031_02250c00;
    int val = *e->field1c;
    struct Pair02225d14 p;
    p.hi = (unsigned int)(val & 0x1ff0000) >> 0x10;
    p.off = (val & 0xff) - 0xc;
    if (p.off > 0x63) {
        func_ov031_022266b0(1, p.off);
        return;
    }
    func_ov031_022266b0(1, 0x63);
    func_ov031_022266b0(2, 0xc0);
    func_ov031_0223e2b8(obj, (int)func_ov031_02225d98);
}

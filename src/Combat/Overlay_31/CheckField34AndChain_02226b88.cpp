#include <globaldefs.h>

struct EntityStruct02226b88 { unsigned char pad[0x34]; int* field34; };
extern EntityStruct02226b88* data_ov031_02250c00;
extern "C" int func_ov031_022266b0(int idx, int t, int b);

struct Obj02226b88 { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(Obj02226b88* obj, int v);
extern "C" void func_ov031_02226bf8(void* obj);

struct Pair02226b88 { int t; int b; };

#pragma optimize_for_size off
// USA: func_ov031_02226b88  (semantic: CheckField34AndChain_02226b88)
extern "C" ARM void func_ov031_02226b88(Obj02226b88* obj) {
    int v = *data_ov031_02250c00->field34;
    Pair02226b88 p;
    Pair02226b88* pp = &p;
    pp->b = (unsigned)(v & 0x1ff0000) >> 16;
    pp->t = (v & 0xff) + 0xc;
    func_ov031_022266b0(3, pp->t, pp->b);
    if (pp->t < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02226bf8);
}

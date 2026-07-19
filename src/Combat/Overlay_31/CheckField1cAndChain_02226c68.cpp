#include <globaldefs.h>

struct EntityStruct02226c68 { unsigned char pad[0x1c]; int* field1c; };
extern EntityStruct02226c68* data_ov031_02250c00;
extern "C" int func_ov031_022266b0(int idx, int t, int b);

struct Obj02226c68 { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(Obj02226c68* obj, int v);
extern "C" void func_ov031_02226cd8(void* obj);

struct Pair02226c68 { int t; int b; };

#pragma optimize_for_size off
// USA: func_ov031_02226c68  (semantic: CheckField1cAndChain_02226c68)
extern "C" ARM void func_ov031_02226c68(Obj02226c68* obj) {
    int v = *data_ov031_02250c00->field1c;
    Pair02226c68 p;
    Pair02226c68* pp = &p;
    pp->b = (unsigned)(v & 0x1ff0000) >> 16;
    pp->t = (v & 0xff) + 0xc;
    func_ov031_022266b0(1, pp->t, pp->b);
    if (pp->t < 0xc0) return;
    func_ov031_0223e2b8(obj, (int)func_ov031_02226cd8);
}

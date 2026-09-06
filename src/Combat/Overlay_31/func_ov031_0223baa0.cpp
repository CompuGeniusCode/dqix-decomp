#include <globaldefs.h>

struct Elem8_02226b10 { int a, b; };
struct ElemArray_02226b10 { int pad0, pad1; Elem8_02226b10* arr; };
extern "C" ARM Elem8_02226b10* func_ov031_0223baa0(ElemArray_02226b10* obj, int idx);

struct EntityStruct02226b10 { unsigned char pad[0x40]; ElemArray_02226b10* field40; };
extern EntityStruct02226b10* data_ov031_02250c00;
extern "C" int func_ov031_022266b0(int idx, int t, int b);

struct Obj02226b10 { unsigned char pad[8]; int field8; };
extern "C" void func_ov031_0223e2b8(Obj02226b10* obj, int v);
extern "C" void func_ov031_02226b88(void* obj);

struct Pair02226b10 { int t; int b; };

#pragma optimize_for_size off
// USA: func_ov031_02226b10  (semantic: CheckElem0AndChain_02226b10)
extern "C" ARM void func_ov031_02226b10(Obj02226b10* obj) {
	int v = func_ov031_0223baa0(data_ov031_02250c00->field40, 0)->a;
	Pair02226b10 p;
	Pair02226b10* pp = &p;
	pp->b = (unsigned)(v & 0x1ff0000) >> 16;
	pp->t = (v & 0xff) + 0xc;
	func_ov031_022266b0(4, pp->t, pp->b);
	if (pp->t < 0xc0) return;
	func_ov031_0223e2b8(obj, (int)func_ov031_02226b88);
}

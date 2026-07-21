#include <globaldefs.h>

extern "C" bool func_ov031_02237eb0();
void SetField_022274c0_022274c0(int v);
void GetFields181c_02227520(int* a, int* b);
extern "C" void func_ov031_0222ce24();
extern "C" void func_ov031_0222d1b8();

struct FuncPtrPair_02248eb4 {
	char pad[0x10];
	void (*fn0)(void*);
	void (*fn1)(void*);
};
extern FuncPtrPair_02248eb4 data_ov031_02248eb4;

struct StructC94_0222d474 {
	char pad0[4];
	unsigned int* field4;
	char pad1[0x2a - 8];
	unsigned char field2a;
};
extern StructC94_0222d474* data_ov031_02290c94;

// USA: func_ov031_0222d474  (semantic: HandleDispatch_0222d474)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222d474() {
	void (*fnTable[2])(void*);
	fnTable[0] = data_ov031_02248eb4.fn0;
	fnTable[1] = data_ov031_02248eb4.fn1;
	if (func_ov031_02237eb0()) {
		return;
	}
	StructC94_0222d474* p = data_ov031_02290c94;
	if (p->field2a == 0) {
		*p->field4 &= 0xc1fffcff;
		SetField_022274c0_022274c0((int)func_ov031_0222ce24);
		return;
	}
	int idx;
	GetFields181c_02227520(&idx, (int*)0);
	p = data_ov031_02290c94;
	void (*fn)(void*) = fnTable[idx];
	fn((char*)p + 8);
	SetField_022274c0_022274c0((int)func_ov031_0222d1b8);
}

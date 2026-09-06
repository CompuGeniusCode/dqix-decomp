#include <globaldefs.h>

struct Obj02154d7c {
	char pad0[8];
	int f8;
	int fc;
	int f10;
	int f14;
	char pad1[0x18];
	int f30;
	int f34;
};

// USA: func_ov005_02154d7c  (semantic: ComputeAdjustedOffsets02154d7c)
extern "C" ARM void func_ov005_02154d7c(Obj02154d7c* obj, int a, int b) {
	obj->f30 = obj->fc + (a - obj->f8);
	obj->f34 = obj->f14 + (b - obj->f10);
}

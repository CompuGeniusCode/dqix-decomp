#include <globaldefs.h>

struct Entry021d4b9c { int f0; int f4; int f8; };
struct Obj021d4b9c {
	unsigned char pad0[0x28];
	Entry021d4b9c* stackPtr;
	unsigned char pad1[4];
	int f30;
	int f34;
};

// USA: func_ov017_021d4b9c
ARM int PopStackEntry_021d4b9c(Obj021d4b9c* obj) {
	obj->stackPtr--;
	obj->f30 = obj->stackPtr->f4;
	obj->f34 = obj->stackPtr->f8;
	return obj->stackPtr->f0;
}

#include <globaldefs.h>

struct Obj02186df0 {
	unsigned char pad0[0xd0];
	short* ptrD0;
	unsigned char pad1[0x17a - 0xd4];
	unsigned char byte17a;
	unsigned char byte17b;
	unsigned char pad2[0x17f - 0x17c];
	unsigned char byte17f;
};

// USA: func_ov014_02186df0
ARM void ResetBattlerNav_02186df0(struct Obj02186df0* o) {
	if (o->byte17f != 0) return;
	o->byte17f = 1;
	short* p = o->ptrD0;
	if (p != NULL) *p = -1;
	o->ptrD0 = NULL;
	o->byte17a = 5;
	o->byte17b = 0;
}

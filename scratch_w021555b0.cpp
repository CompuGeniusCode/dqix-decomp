#include <globaldefs.h>

struct P2Struct021555b0 {
	short f0;
	unsigned short bit0 : 1;
	unsigned short bit1 : 1;
	unsigned short restBits : 14;
};

struct Obj021555b0 {
	char pad0[0x1b4];
	short* p1b4;
	short* p1b8;
	char pad1[0x1c0 - 0x1bc];
	void* p1c0;
};

extern "C" void func_ov006_02155508(Obj021555b0* o);
extern "C" void func_ov006_02155630(Obj021555b0* o, short* p1, P2Struct021555b0* p2);

ARM void Func021555b0(Obj021555b0* o, short* p1, P2Struct021555b0* p2) {
	if (p1 == NULL || p2 == NULL) {
		if (o->p1c0 == p2) return;
		func_ov006_02155508(o);
		return;
	}
	if (p2 == NULL || p2->bit1 == 0) {
		func_ov006_02155508(o);
		return;
	}
	if (o->p1b4 != NULL && *o->p1b4 == *p1) return;
	if (o->p1b8 != NULL && *o->p1b8 == *p1) return;
	func_ov006_02155630(o, p1, p2);
}

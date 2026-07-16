#include <globaldefs.h>

struct Struct0223c2d0 {
	unsigned char pad0[4];
	short field4;
	unsigned short field6;
	unsigned char field8;
	unsigned char field9;
};

extern "C" void func_ov031_0223e2c0(int, void*);

// USA: func_ov031_0223c2d0
ARM void IncrementCounterAndMaybeFire_0223c2d0(void* a, Struct0223c2d0* s) {
	s->field4 = s->field4 + 1;
	if (s->field4 < s->field6) {
		return;
	}
	s->field9 = 0;
	func_ov031_0223e2c0(1, a);
}

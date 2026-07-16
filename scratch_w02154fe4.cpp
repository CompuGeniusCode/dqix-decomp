#include <globaldefs.h>

extern "C" void func_ov023_021dfad8(void* p);
extern "C" void func_0207fd88(void* p);

struct Obj02154fe4 {
	char pad0[0x1d4];
	void* field1d4;
	char pad1[0xadc - 0x1d8];
	unsigned char flag_adc;
	char pad2[0x127f - 0xadd];
	unsigned char flag27f;
	char pad3[0x12bd - 0x1280];
	unsigned char flag2bd;
};

struct Flags027f02154fe4 {
	unsigned char bit0 : 1;
	unsigned char bit1 : 1;
	unsigned char rest : 6;
};

// USA: func_ov006_02154fe4
ARM void HandleStateTransition02154fe4(Obj02154fe4* o) {
	if (o->flag_adc == 0) {
		return;
	}
	if (o->flag2bd != 0) {
		volatile unsigned int* reg = (volatile unsigned int*)0x4000000;
		unsigned int field = (*reg & 0x1f00) >> 8;
		*reg = (*reg & ~0x1f00) | ((field | 1) << 8);
		o->flag2bd = 0;
	}
	func_ov023_021dfad8((char*)o + 0x2e4 + 0x800);
	if (((Flags027f02154fe4*)&o->flag27f)->bit1) {
		return;
	}
	if (o->field1d4 == NULL) {
		return;
	}
	func_0207fd88(o->field1d4);
}

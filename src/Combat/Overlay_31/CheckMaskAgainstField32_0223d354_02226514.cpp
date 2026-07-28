#include <globaldefs.h>

extern "C" int func_ov031_0223d394(int);
extern "C" void func_ov031_02226a64(int);
extern "C" int func_ov031_02236878(int);
ARM int CheckMaskAgainstField32_0223d354(int mask);
ARM int CheckMaskAgainstField36_0223d3d4(int mask);

struct Obj02226514 {
	unsigned char pad60[0x60];
	unsigned char field60;
	unsigned char pad61[2];
	signed char state;
	unsigned char pad64[2];
	unsigned char field66;
	unsigned char field67;
	unsigned char field68;
	unsigned char field69;
};
extern Obj02226514* data_ov031_02250c00;
extern unsigned char data_ov031_02248d74[];
extern unsigned char data_ov031_02248c84[];
extern unsigned char data_ov031_02248c80[];

// USA: func_ov031_02226514
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02226514(void) {
	if (func_ov031_0223d394(0x20)) func_ov031_02226a64(0);
	if (func_ov031_0223d394(0x40)) func_ov031_02226a64(1);
	if (func_ov031_0223d394(0x10)) func_ov031_02226a64(2);
	if (func_ov031_0223d394(0x80)) func_ov031_02226a64(3);

	if (CheckMaskAgainstField32_0223d354(1)) {
		Obj02226514* p = data_ov031_02250c00;
		int state = p->state;
		if (state < 10) {
			if (p->field67 != 0) {
				p->field60 = data_ov031_02248d74[state];
				return;
			}
			func_ov031_02236878(9);
			return;
		} else {
			if (state - 0xa < 2) {
				if (state - 0xa != 0 || p->field66 != 0) {
					if (state - 0xa != 1 || p->field68 != 0) goto set60;
				}
				func_ov031_02236878(9);
				return;
			set60:
				p->field60 = data_ov031_02248c84[state - 0xa];
				return;
			}
			p->field60 = data_ov031_02248c80[state - 0xc];
		}
	}

	if (func_ov031_0223d394(2)) {
		Obj02226514* p = data_ov031_02250c00;
		if (p->field66 == 0) {
			if (p->field69 != 0) return;
			func_ov031_02236878(9);
			data_ov031_02250c00->field69 = 1;
			return;
		}
		p->field60 = 0x10;
		return;
	}
	if (CheckMaskAgainstField36_0223d3d4(2) == 0) return;
	data_ov031_02250c00->field69 = 0;
}

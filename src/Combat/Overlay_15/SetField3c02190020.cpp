#include <globaldefs.h>

struct Obj02190020 {
	char pad1c[0x1c];
	unsigned char state;
	char pad24[0x24 - 0x1d];
	int* ptr24;
	char pad2c[0x2c - 0x28];
	unsigned char flag2c;
	char pad3c[0x3c - 0x2d];
	unsigned char field3c;
};

// USA: func_ov015_02190020
ARM void SetField3c02190020(struct Obj02190020* obj, unsigned char val) {
	char* p;
	if (obj->state != 0 && obj->state != 1) {
		return;
	}
	if (obj->field3c == val) {
		return;
	}
	p = (char*)obj->ptr24 + 0x200;
	*(short*)(p + 0xb2) = -1;
	obj->field3c = val;
	obj->flag2c = 1;
}

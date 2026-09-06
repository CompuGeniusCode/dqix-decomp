#include <globaldefs.h>

struct Struct0217193c {
	unsigned char pad0[0x84];
	unsigned short f84;
	unsigned char pad1[0x1a4 - 0x86];
	int arr1a4[0x93];
};

// USA: func_ov000_0217193c
ARM void ZeroArr1a4AndFlag0x840217193c(struct Struct0217193c* obj) {
	int i;
	for (i = 0; i < 0x93; i++) {
		obj->arr1a4[i] = 0;
	}
	obj->f84 = 0;
}

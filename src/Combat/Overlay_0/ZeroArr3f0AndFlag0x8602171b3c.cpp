#include <globaldefs.h>

struct Struct02171b3c {
	unsigned char pad0[0x86];
	unsigned char f86;
	unsigned char pad1[0x3f0 - 0x87];
	int arr3f0[0x10];
};

// USA: func_ov000_02171b3c
ARM void ZeroArr3f0AndFlag0x8602171b3c(struct Struct02171b3c* obj) {
	int i;
	for (i = 0; i < 0x10; i++) {
		obj->arr3f0[i] = 0;
	}
	obj->f86 = 0;
}

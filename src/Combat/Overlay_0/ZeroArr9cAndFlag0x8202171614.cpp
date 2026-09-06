#include <globaldefs.h>

struct Struct02171614 {
	unsigned char pad0[0x82];
	unsigned short f82;
	unsigned char pad1[0x9c - 0x84];
	int arr9c[0x42];
};

// USA: func_ov000_02171614
ARM void ZeroArr9cAndFlag0x8202171614(struct Struct02171614* obj) {
	int i;
	for (i = 0; i < 0x42; i++) {
		obj->arr9c[i] = 0;
	}
	obj->f82 = 0;
}

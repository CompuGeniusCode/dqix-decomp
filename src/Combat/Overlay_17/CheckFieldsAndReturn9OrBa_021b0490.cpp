#include <globaldefs.h>

struct S021b0490 {
	unsigned char pad0[9];
	unsigned char b9;
	unsigned char ba;
	unsigned char pad1[0x23 - 0xb];
	unsigned char b23;
	unsigned char b24;
	unsigned char pad2[0x30 - 0x25];
	int f30;
};

// USA: func_ov017_021b0490
ARM int CheckFieldsAndReturn9OrBa_021b0490(S021b0490* p) {
	if (p->b9 == 0) {
		if (p->f30 != 0) {
			p->b23 = 0;
			p->b24 = 0;
			return 9;
		}
	}
	return p->ba;
}

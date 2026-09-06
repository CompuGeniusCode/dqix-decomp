#include <globaldefs.h>

extern "C" void func_020ca3b8(int a, void* p, int size);

struct Struct021dad14 {
	unsigned char pad0[0x358];
	unsigned char cnt358;
	unsigned char pad1;
	unsigned short val35a;
	unsigned short val35c;
	unsigned char sub35e[0x156];
	unsigned char cnt4b4;
};

// USA: func_ov027_021dad14
ARM void SetupCombatFlags_021dad14(Struct021dad14* s, int a, unsigned int flags, int c) {
	unsigned char cnt = 1;
	func_020ca3b8(a, &s->sub35e, 0x14a);
	int i = 0;
	do {
		if (flags & (2 << i)) cnt = (cnt + 1) & 0xff;
		i++;
	} while (i < 15);
	s->cnt358 = cnt;
	s->val35a = flags | 1;
	s->val35c = c;
	s->cnt4b4 = s->cnt4b4 + 1;
}

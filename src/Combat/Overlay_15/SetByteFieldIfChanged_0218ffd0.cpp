#include <globaldefs.h>

struct S_0218ffd0 { char pad[0x1c]; unsigned char flag1c; char pad2[0xf]; unsigned char dirty2c; char pad3[0x10]; unsigned char field3d; };

// USA: func_ov015_0218ffd0
ARM void SetByteFieldIfChanged_0218ffd0(struct S_0218ffd0* o, int val) {
	unsigned char f = o->flag1c;
	if (f != 0 && f != 1)
		return;
	if (o->field3d != val) {
		o->field3d = val;
		o->dirty2c = 1;
	}
}

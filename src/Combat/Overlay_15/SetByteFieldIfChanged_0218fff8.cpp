#include <globaldefs.h>

struct S_0218fff8 { char pad[0x1c]; unsigned char flag1c; char pad2[0xf]; unsigned char dirty2c; char pad3[0x11]; unsigned char field3e; };

// USA: func_ov015_0218fff8
ARM void SetByteFieldIfChanged_0218fff8(struct S_0218fff8* o, int val) {
	unsigned char f = o->flag1c;
	if (f != 0 && f != 1)
		return;
	if (o->field3e != val) {
		o->field3e = val;
		o->dirty2c = 1;
	}
}

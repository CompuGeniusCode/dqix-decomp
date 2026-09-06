#include <globaldefs.h>

struct S_0218ffa8 { char pad[0x1c]; unsigned char flag1c; char pad2[0xf]; unsigned char dirty2c; char pad3[0xe]; unsigned char field3b; };

// USA: func_ov015_0218ffa8
ARM void SetByteFieldIfChanged_0218ffa8(struct S_0218ffa8* o, int val) {
	unsigned char f = o->flag1c;
	if (f != 0 && f != 1)
		return;
	if (o->field3b != val) {
		o->field3b = val;
		o->dirty2c = 2;
	}
}

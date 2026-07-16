#include <globaldefs.h>

struct Struct021847c4 { int a, b, c, d, e, f, g, h; };

void ResetFields021847c4(struct Struct021847c4 *s);

extern short data_ov009_0218ac04[];

ARM void FillGroupFromTable02188d9c(void *base) {
	ResetFields021847c4((struct Struct021847c4*)((char*)base + 0x2c + 0xc00));
	signed char *entry = (signed char*)((char*)base + 0xc00);
	short *table = data_ov009_0218ac04;
	int i = 0;
	while (table[i] >= 0) {
		if (entry[0x58] == (int)base) {
			int i1 = i+1, i2 = i+2, i3 = i+3, i4 = i+4, i5 = i+5, i6 = i+6, i7 = i+7, i8 = i+8;
			int *out = (int*)((char*)base + 0x2c + 0xc00);
			out[0] = table[i1];
			out[1] = table[i2];
			out[2] = table[i3];
			out[3] = table[i4];
			out[4] = table[i5];
			out[5] = table[i6];
			out[6] = table[i7];
			out[7] = table[i8];
			return;
		}
		i += 9;
	}
}

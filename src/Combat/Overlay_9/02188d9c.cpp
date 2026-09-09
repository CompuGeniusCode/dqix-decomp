#include <globaldefs.h>

struct Struct021847c4 { int a, b, c, d, e, f, g, h; };

extern "C" void _Z19ResetFields021847c4P14Struct021847c4(struct Struct021847c4 *s);

extern const short data_ov009_0218ac04[];

// USA: func_ov009_02188d9c
extern "C" ARM void func_ov009_02188d9c(void *self) {
	int *out = (int*)((char*)self + 0xc2c);
	int i;

	_Z19ResetFields021847c4P14Struct021847c4((struct Struct021847c4*)out);

	i = 0;
	while (data_ov009_0218ac04[i] >= 0) {
		if (*(signed char*)((char*)self + 0xc58) == data_ov009_0218ac04[i]) {
			int i1 = i + 1;
			int i2 = i + 2;
			int i3 = i + 3;
			int i4 = i + 4;
			int i5 = i + 5;
			int i6 = i + 6;
			int i7 = i + 7;
			int i8 = i + 8;
			out[0] = data_ov009_0218ac04[i1];
			out[1] = data_ov009_0218ac04[i2];
			out[2] = data_ov009_0218ac04[i3];
			out[3] = data_ov009_0218ac04[i4];
			out[4] = data_ov009_0218ac04[i5];
			out[5] = data_ov009_0218ac04[i6];
			out[6] = data_ov009_0218ac04[i7];
			out[7] = data_ov009_0218ac04[i8];
			return;
		}
		i += 9;
	}
}

#include <globaldefs.h>

struct Ctx0223566c {
	unsigned char pad0[0x10];
	unsigned short field10;
	unsigned short field12;
	unsigned char pad14[0x19 - 0x14];
	unsigned char field19;
	unsigned char field1a;
	unsigned char field1b;
};
extern Ctx0223566c* data_ov031_02290cf4;
extern unsigned char data_ov031_022491f4[];

struct Out0223566c { unsigned short f0; unsigned short f2; unsigned short f4; unsigned short f6; };

// USA: func_ov031_0223566c
extern "C" ARM void func_ov031_0223566c(int idx, Out0223566c* out) {
	unsigned short v10 = data_ov031_02290cf4->field10;
	out->f0 = v10;
	out->f4 = v10 + 0xc;
	switch (idx) {
	case 0:
		break;
	case 1:
		out->f2 = data_ov031_02290cf4->field12 + data_ov031_02290cf4->field1a;
		out->f6 = out->f2 + data_ov031_022491f4[data_ov031_02290cf4->field1b];
		break;
	case 2:
		out->f2 = data_ov031_02290cf4->field12 - 0xd;
		out->f6 = data_ov031_02290cf4->field12;
		break;
	case 3:
		out->f2 = data_ov031_02290cf4->field12 + data_ov031_02290cf4->field19;
		out->f6 = out->f2 + 0xd;
		break;
	case 4:
		out->f2 = data_ov031_02290cf4->field12;
		out->f6 = out->f2 + data_ov031_02290cf4->field19;
		break;
	}
}

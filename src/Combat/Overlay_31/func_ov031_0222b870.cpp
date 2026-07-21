#include <globaldefs.h>

int Divide32(int numer, unsigned int denom);
extern "C" void func_ov031_022350bc(int a, int b, int c, int d, int e);

struct Inner0222b870 {
	unsigned char pad[0x40];
	unsigned short field40;
	unsigned char pad2[0x51 - 0x42];
	unsigned char field51;
	unsigned char pad3[1];
	unsigned char field53;
};
struct Struct0222b870 {
	unsigned char pad[2];
	unsigned short field2;
	Inner0222b870* field4;
};
extern Struct0222b870 data_ov031_02290c8c;

// USA: func_ov031_0222b870
#pragma optimize_for_size off
extern "C" ARM void func_ov031_0222b870(void) {
	int div = 0;
	Inner0222b870* obj = data_ov031_02290c8c.field4;
	obj->field40 = (obj->field51 - 4) * 0x1c;

	obj = data_ov031_02290c8c.field4;
	unsigned char v = obj->field51;
	int flag;
	if (v <= 4) {
		obj->field53 = 0;
		flag = 0;
	} else if (v <= 8) {
		obj->field53 = 0x1f;
		flag = 1;
	} else {
		obj->field53 = 0x37;
		flag = 2;
	}

	if (flag != 0) {
		obj = data_ov031_02290c8c.field4;
		unsigned short cnt = data_ov031_02290c8c.field2;
		unsigned char sz = obj->field53;
		unsigned short f40 = obj->field40;
		div = Divide32(cnt * sz, f40);
	}
	func_ov031_022350bc(flag, 0x55, 0xec, 0x3f, div);
}

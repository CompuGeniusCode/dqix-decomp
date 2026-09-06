#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(int size, int align);
void GetFields181c_02227520(int* a, int* b);
extern "C" int func_ov031_02235984(void* ptr);
extern "C" void func_ov031_0222b71c(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_0222336c(int a, int b, int c);
extern "C" void func_ov031_02223518(int a);
extern "C" void func_ov031_0222b870(void);
extern "C" void func_ov031_0222b918(void);
extern "C" void* func_ov031_0223c560(int a, int b);
void* CallWithZeroExtra_0223e218(void* a, void* b, void* c, int d);
extern "C" void func_ov031_0222c870(void);
extern "C" void func_ov031_0222c3b4(void);
extern "C" void func_ov031_0222c8cc(void);
extern "C" void func_ov031_0222ba8c(void);
void SetField_022274c0_022274c0(int v);

struct Inner0222b644 {
	unsigned char pad[0xc];
	void* field0xc;
	unsigned char pad2[0x3c - 0x10];
	int field0x3c;
	unsigned char pad3[0x51 - 0x40];
	unsigned char field0x51;
};
struct Struct0222b644 {
	unsigned char field0;
	unsigned char pad1;
	unsigned short field2;
	Inner0222b644* field4;
};
extern Struct0222b644 data_ov031_02290c8c;

#pragma optimize_for_size off
// USA: func_ov031_0222b644
extern "C" ARM void func_ov031_0222b644(void) {
	int local;
	data_ov031_02290c8c.field4 = (Inner0222b644*)func_ov031_0223cf4c(0x5c, 4);
	GetFields181c_02227520(&local, NULL);
	if (local == 0) {
		data_ov031_02290c8c.field0 = 0;
		data_ov031_02290c8c.field2 = 0;
	}

	data_ov031_02290c8c.field4->field0x51 = (unsigned char)func_ov031_02235984(data_ov031_02290c8c.field4);

	func_ov031_0222b71c();
	func_ov031_022239f4();
	func_ov031_0222336c(0x34, -1, 0);
	func_ov031_02223518(2);
	func_ov031_0222b870();
	func_ov031_0222b918();

	data_ov031_02290c8c.field4->field0xc = func_ov031_0223c560(0, 0);
	data_ov031_02290c8c.field4->field0x3c = (int)CallWithZeroExtra_0223e218((void*)1, (void*)func_ov031_0222c870, NULL, 0x6e);

	func_ov031_0222c3b4();
	func_ov031_0222c8cc();
	SetField_022274c0_022274c0((int)func_ov031_0222ba8c);
}

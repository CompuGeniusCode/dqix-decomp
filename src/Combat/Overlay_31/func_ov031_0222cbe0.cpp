#include <globaldefs.h>

extern unsigned char data_ov031_02248eb4[2];
extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);

extern void* data_ov031_02290c94;

extern void GetFields181c_02227520(int*, int*);
extern "C" void func_ov031_02235f0c(void*);
extern int FindFirstZeroByte_0223dd34(unsigned char*, int);
extern "C" void func_ov031_0222cd14(void);
extern "C" void func_ov031_02223998(int);
extern "C" void func_ov031_0222336c(int, int, int);
extern "C" void func_ov031_02223518(int);
extern "C" int func_ov031_0223c560(int, int);
extern int CallTailCallThenBdb0_0223be44(int, int);
extern "C" void func_ov031_0222d3b0(void);
extern "C" void func_ov031_0222d2bc(void);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222cdd0(void);

struct BitsAt4_0222cbe0 { unsigned char pad[4]; unsigned short pad2 : 10; unsigned short field2bit : 2; };

// USA: func_ov031_0222cbe0  (semantic: AllocAndSetupThenDispatch_0222cbe0)
extern "C" ARM void func_ov031_0222cbe0(void) {
	unsigned char localbuf[2];
	localbuf[0] = data_ov031_02248eb4[0];
	localbuf[1] = data_ov031_02248eb4[1];
	data_ov031_02290c94 = func_ov031_0223cf4c(0x2c, 4);

	int local8, local4;
	GetFields181c_02227520(&local8, &local4);

	if (local8 == 0) {
		func_ov031_02235f0c((char*)data_ov031_02290c94 + 8);
		unsigned char idx = FindFirstZeroByte_0223dd34((unsigned char*)((char*)data_ov031_02290c94 + 8), 0x20);
		*((unsigned char*)data_ov031_02290c94 + 0x29) = idx;
	}
	func_ov031_0222cd14();
	func_ov031_02223998(local8 + 9);
	if (local4 == 1) {
		func_ov031_0222336c(0x35, -1, 0);
	} else {
		func_ov031_0222336c(localbuf[local8], -1, 0);
	}
	func_ov031_02223518(2);
	int r = func_ov031_0223c560(0, 0);
	*(int*)data_ov031_02290c94 = r;
	int r2 = CallTailCallThenBdb0_0223be44(0, 0x3e);
	*(int*)((char*)data_ov031_02290c94 + 4) = r2;
	BitsAt4_0222cbe0* p = *(BitsAt4_0222cbe0**)((char*)data_ov031_02290c94 + 4);
	p->field2bit = 3;
	func_ov031_0222d3b0();
	func_ov031_0222d2bc();
	SetField_022274c0_022274c0((int)func_ov031_0222cdd0);
}

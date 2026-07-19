#include <globaldefs.h>

extern unsigned char data_ov031_02290c88;
extern "C" void func_ov031_0222b48c(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222b4f8(void);

// USA: func_ov031_0222b450  (semantic: InitResetAndSetHandler_0222b450)
extern "C" ARM void func_ov031_0222b450(void) {
	data_ov031_02290c88 = 0;
	func_ov031_0222b48c();
	func_ov031_022239f4();
	func_ov031_022235a0(0x23);
	func_ov031_02236878(0x10);
	SetField_022274c0_022274c0((int)func_ov031_0222b4f8);
}

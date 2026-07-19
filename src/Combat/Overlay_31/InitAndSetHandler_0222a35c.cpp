#include <globaldefs.h>

extern "C" void func_ov031_0222a398(void);
extern "C" void func_ov031_022235a0(int);
extern "C" int func_ov031_0222336c(int, int, int);
extern unsigned char data_ov031_02290c74[];
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a418(void);

// USA: func_ov031_0222a35c  (semantic: InitAndSetHandler_0222a35c)
extern "C" ARM void func_ov031_0222a35c(void) {
	func_ov031_0222a398();
	func_ov031_022235a0(0x20);
	data_ov031_02290c74[0] = func_ov031_0222336c(0x3c, 0x3c - 0x3d, 0);
	SetField_022274c0_022274c0((int)func_ov031_0222a418);
}

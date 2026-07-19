#include <globaldefs.h>

extern "C" void func_ov031_022276f8(int);
extern "C" void func_ov031_0222ae38(void);
extern unsigned char data_ov031_02290c7c;
extern "C" void func_ov031_0222ab08(void);
extern "C" void func_ov031_022235a0(int);
extern "C" void func_ov031_02222b0c(int);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222ab88(void);

// USA: func_ov031_0222aabc  (semantic: InitAndSetHandler_0222aabc)
extern "C" ARM void func_ov031_0222aabc(void) {
	func_ov031_022276f8((int)func_ov031_0222ae38);
	data_ov031_02290c7c = 0;
	func_ov031_0222ab08();
	func_ov031_022235a0(0x1c);
	func_ov031_02222b0c(0);
	func_ov031_02236878(0xb);
	SetField_022274c0_022274c0((int)func_ov031_0222ab88);
}

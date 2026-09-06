#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" int func_ov031_0223c078(int, int, int, int);
extern int IsPtr02290c44Null_02227840(void);
extern int TailCall_02222ddc(void);
extern void SetField_022274c0_022274c0(int);
extern unsigned char data_ov031_02290c7c;
extern "C" void func_ov031_0222ad40(void);

// USA: func_ov031_0222acc0
ARM void RunSetupAndRegisterHandler_0222acc0(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (data_ov031_02290c7c == 0) {
		if (IsPtr02290c44Null_02227840() == 0) return;
	}
	TailCall_02222ddc();
	if (data_ov031_02290c7c == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_0222ad40);
}

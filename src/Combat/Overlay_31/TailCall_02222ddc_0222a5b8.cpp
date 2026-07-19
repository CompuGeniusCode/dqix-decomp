#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
ARM void RunChecksAndSetHandler_0222a61c(void);
extern unsigned char data_ov031_02290c74[];

// USA: func_ov031_0222a5b8  (semantic: CheckFlagThenRunSetupAndSetHandler_0222a5b8)
extern "C" ARM void func_ov031_0222a5b8(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	TailCall_02222ddc();
	if (data_ov031_02290c74[1] == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_0222a61c);
}

#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void TailCall_02222ddc(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
ARM void RunChecksAndSetHandler_02228858(void);
extern unsigned char data_ov031_02290c58;

// USA: func_ov031_022287f4  (semantic: CheckFlagThenRunSetupAndSetHandler_022287f4)
extern "C" ARM void func_ov031_022287f4(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	TailCall_02222ddc();
	if (data_ov031_02290c58 == 0) {
		func_ov031_0223c078(3, 1, 1, 8);
	}
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_02228858);
}

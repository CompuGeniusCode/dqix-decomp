#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02237b2c(int, int, int, int, int);
ARM void SetField_022274c0_022274c0(int);
ARM void RunStubsThenRegister_02231058(void);

// USA: func_ov031_02231008  (semantic: CallStubThenSetHandler_02231008)
extern "C" ARM void func_ov031_02231008(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02237b2c(0x44, 5, 1, -1, 0);
	SetField_022274c0_022274c0((int)RunStubsThenRegister_02231058);
}

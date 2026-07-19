#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a2c4(void);

// USA: func_ov031_0222a288  (semantic: RunSetupAndSetHandler_0222a288)
extern "C" ARM void func_ov031_0222a288(void) {
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)func_ov031_0222a2c4);
}

#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02227d20(void);

// USA: func_ov031_02227ce4  (semantic: CallStubsThenSetHandler_02227ce4)
extern "C" ARM void func_ov031_02227ce4(void) {
	func_ov031_0223c078(3, 1, 0x3f, 0x14);
	func_ov031_0223c078(3, 0, 0x3f, 0x14);
	SetField_022274c0_022274c0((int)func_ov031_02227d20);
}

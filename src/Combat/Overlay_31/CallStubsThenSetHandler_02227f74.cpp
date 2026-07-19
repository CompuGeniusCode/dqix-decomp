#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02227fb0(void);

// USA: func_ov031_02227f74  (semantic: CallStubsThenSetHandler_02227f74)
extern "C" ARM void func_ov031_02227f74(void) {
	func_ov031_0223c078(2, 1, 2, 0x14);
	func_ov031_0223c078(2, 0, 2, 0x14);
	SetField_022274c0_022274c0((int)func_ov031_02227fb0);
}

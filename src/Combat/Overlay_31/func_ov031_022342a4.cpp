#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022342d8(void);

// USA: func_ov031_022342a4  (semantic: CallStubsThenSetHandler_022342a4)
extern "C" ARM void func_ov031_022342a4(void) {
	if (func_ov031_02237eb0() != 0) return;
	func_ov031_0223c078(3, 0, 0x14, 8);
	SetField_022274c0_022274c0((int)func_ov031_022342d8);
}

#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern void SetField_022274c0_022274c0(int);
extern void AdvanceIfNotFlag0_02229aa8(void);

// USA: func_ov031_02229a74  (semantic: CallStubsThenSetHandler_02229a74)
extern "C" ARM void func_ov031_02229a74(void) {
	func_ov031_0223c078(2, 0, 0x15, 8);
	func_ov031_0223cb68(0, 0x15);
	SetField_022274c0_022274c0((int)AdvanceIfNotFlag0_02229aa8);
}

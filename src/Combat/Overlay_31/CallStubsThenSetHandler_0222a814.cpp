#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern void SetField_022274c0_022274c0(int);
extern void AdvanceIfNotFlag0_0222a848(void);

// USA: func_ov031_0222a814  (semantic: CallStubsThenSetHandler_0222a814)
extern "C" ARM void func_ov031_0222a814(void) {
	func_ov031_0223c078(2, 0, 0x15, 8);
	func_ov031_0223cb68(0, 0x15);
	SetField_022274c0_022274c0((int)AdvanceIfNotFlag0_0222a848);
}

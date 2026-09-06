#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229860(void);

// USA: func_ov031_0222982c  (semantic: CallStubsThenSetHandler_0222982c)
extern "C" ARM void func_ov031_0222982c(void) {
	func_ov031_0223c078(2, 0, 0x15, 8);
	func_ov031_0223cb68(0, 0x15);
	SetField_022274c0_022274c0((int)func_ov031_02229860);
}

#include <globaldefs.h>

extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_0223cb68(int, int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022327d4(void);

// USA: func_ov031_02232780  (semantic: SetupStubPairThenDispatch_02232780)
extern "C" ARM void func_ov031_02232780(void) {
	func_ov031_0223c078(2, 1, 1, 8);
	func_ov031_0223c078(2, 0, 0x14, 8);
	func_ov031_0223cb68(1, 1);
	func_ov031_0223cb68(0, 0x14);
	SetField_022274c0_022274c0((int)func_ov031_022327d4);
}

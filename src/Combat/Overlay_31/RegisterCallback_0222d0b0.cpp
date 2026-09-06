#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223f6c(void);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern void DispatchByField2aByte_0222d0e0(void);

// USA: func_ov031_0222d0b0  (semantic: RegisterCallback_0222d0b0)
extern "C" ARM void func_ov031_0222d0b0(void) {
	if (func_ov031_0223c054(1) != 0) return;
	func_ov031_02223f6c();
	func_ov031_02236878(0x15);
	SetField_022274c0_022274c0((int)DispatchByField2aByte_0222d0e0);
}

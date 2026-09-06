#include <globaldefs.h>

ARM void SetField18_02222e98(void);
extern "C" void func_ov031_0223c278(int);
ARM void SetField_022274c0_022274c0(int);
ARM void RegisterCallback_022323a0(void);

// USA: func_ov031_02232380  (semantic: RegisterCallback_02232380)
extern "C" ARM void func_ov031_02232380(void) {
	SetField18_02222e98();
	func_ov031_0223c278(8);
	SetField_022274c0_022274c0((int)RegisterCallback_022323a0);
}

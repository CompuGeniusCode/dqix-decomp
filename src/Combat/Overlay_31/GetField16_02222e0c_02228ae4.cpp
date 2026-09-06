#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int);
ARM void SetField_022274c0_022274c0(int);
ARM void RegisterCallback_02228b0c(void);

// USA: func_ov031_02228ae4  (semantic: AdvanceUnlessField16Active_02228ae4)
extern "C" ARM void func_ov031_02228ae4(void) {
	if (GetField16_02222e0c() != 0) {
		return;
	}
	func_ov031_02236878(6);
	SetField_022274c0_022274c0((int)RegisterCallback_02228b0c);
}

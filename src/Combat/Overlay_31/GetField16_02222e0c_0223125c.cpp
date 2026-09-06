#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02231284(void);

// USA: func_ov031_0223125c
ARM void RegisterCallbackIfField16Active_0223125c(void) {
	if (GetField16_02222e0c() == -2) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)func_ov031_02231284);
}

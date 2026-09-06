#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM int RunThreeSteps_0222e890(void);

// USA: func_ov031_0222e868
ARM void RegisterCallbackIfField16Active_0222e868(void) {
	if (GetField16_02222e0c() == -2) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_0222e890);
}

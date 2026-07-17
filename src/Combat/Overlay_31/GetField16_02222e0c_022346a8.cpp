#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RunThreeSteps_022346d0(void);

// USA: func_ov031_022346a8
ARM void RegisterCallback_022346a8(void) {
	if (GetField16_02222e0c() == -1) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_022346d0);
}

#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RunThreeInitSteps_02234a90(void);

// USA: func_ov031_02234a68
ARM void RegisterCallback_02234a68(void) {
	if (GetField16_02222e0c() == -1) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeInitSteps_02234a90);
}

#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RunFourInitSteps_022321ec(void);

// USA: func_ov031_022321c4
ARM void RegisterCallbackIfField16Active_022321c4(void) {
	if (GetField16_02222e0c() == -2) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunFourInitSteps_022321ec);
}

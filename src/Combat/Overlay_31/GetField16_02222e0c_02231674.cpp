#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RunFourSteps_0223169c(void);

// USA: func_ov031_02231674
ARM void RegisterCallbackIfField16Active_02231674(void) {
	if (GetField16_02222e0c() == -2) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunFourSteps_0223169c);
}

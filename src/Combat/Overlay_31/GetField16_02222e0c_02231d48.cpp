#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
ARM void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RunFiveSteps_02231d70(void);

// USA: func_ov031_02231d48
ARM void RegisterCallbackIfField16Active_02231d48(void) {
	if (GetField16_02222e0c() == -2) {
		return;
	}
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunFiveSteps_02231d70);
}

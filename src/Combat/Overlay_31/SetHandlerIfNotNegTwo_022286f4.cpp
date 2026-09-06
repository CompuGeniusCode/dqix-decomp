#include <globaldefs.h>

int GetField16_02222e0c(void);
void ClearField18_02222e80(void);
void SetField_022274c0_022274c0(int v);
void RunThreeSteps_0222871c(void);

// USA: func_ov031_022286f4
ARM void SetHandlerIfNotNegTwo_022286f4(void) {
	if (GetField16_02222e0c() == -2) return;
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_0222871c);
}

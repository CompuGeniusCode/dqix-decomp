#include <globaldefs.h>

int GetField16_02222e0c(void);
void ClearField18_02222e80(void);
void SetField_022274c0_022274c0(int v);
void RunThreeSteps_022346d0(void);

// USA: func_ov031_022346a8  (semantic: SetHandlerIfNotNegTwo_022346a8)
extern "C" ARM void func_ov031_022346a8(void) {
	if (GetField16_02222e0c() == -2) return;
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_022346d0);
}

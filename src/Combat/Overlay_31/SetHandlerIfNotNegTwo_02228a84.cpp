#include <globaldefs.h>

int GetField16_02222e0c(void);
void ClearField18_02222e80(void);
void SetField_022274c0_022274c0(int v);
void RunThreeSteps_02228aac(void);

// USA: func_ov031_02228a84  (semantic: SetHandlerIfNotNegTwo_02228a84)
extern "C" ARM void func_ov031_02228a84(void) {
	if (GetField16_02222e0c() == -2) return;
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_02228aac);
}

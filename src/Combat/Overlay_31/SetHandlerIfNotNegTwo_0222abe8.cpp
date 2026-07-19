#include <globaldefs.h>

int GetField16_02222e0c(void);
void SetField_022274c0_022274c0(int v);
int RunThreeSteps_0222ac0c(void);

// USA: func_ov031_0222abe8  (semantic: SetHandlerIfNotNegTwo_0222abe8)
extern "C" ARM void func_ov031_0222abe8(void) {
	if (GetField16_02222e0c() == -2) return;
	SetField_022274c0_022274c0((int)RunThreeSteps_0222ac0c);
}

#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
void ClearField18_02222e80(void);
void SetField_022274c0_022274c0(int v);
void RunThreeSteps_02232844(void);

// USA: func_ov031_02233154  (semantic: CheckFlagThenClearField18AndSetHandler_02233154)
extern "C" ARM void func_ov031_02233154(void) {
	if (func_ov031_02237eb0() != 0) return;
	ClearField18_02222e80();
	SetField_022274c0_022274c0((int)RunThreeSteps_02232844);
}

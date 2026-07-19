#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
extern int RunThreeSteps_02233c74(void);

// USA: func_ov031_02233c40  (semantic: CheckTwoFlagsThenSetHandler_02233c40)
extern "C" ARM void func_ov031_02233c40(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	SetField_022274c0_022274c0((int)RunThreeSteps_02233c74);
}

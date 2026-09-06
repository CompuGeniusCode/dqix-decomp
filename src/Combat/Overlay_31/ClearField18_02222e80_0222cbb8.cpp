#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void ClearField18_02222e80(void);
ARM void ClearField1e_02235204(void);
ARM void SetField_022274c0_022274c0(int);
ARM int RunThreeSteps_0222bb44(void);

// USA: func_ov031_0222cbb8
ARM void RegisterCallbackAndReset_0222cbb8(void) {
	if (func_ov031_02237eb0() != 0) {
		return;
	}
	ClearField18_02222e80();
	ClearField1e_02235204();
	SetField_022274c0_022274c0((int)RunThreeSteps_0222bb44);
}

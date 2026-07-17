#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
void TailCallOffset94_02236878(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222e8f0(void);

// USA: func_ov031_0222e8c8
ARM void RegisterCallbackIfActive_0222e8c8(void) {
	if (GetField16_02222e0c() != 0) {
		return;
	}
	TailCallOffset94_02236878(6);
	SetField_022274c0_022274c0((int)func_ov031_0222e8f0);
}

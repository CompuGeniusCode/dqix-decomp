#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
extern "C" void func_ov031_02225bf0(void);
void TailCallOffset94_02236878(int);
void CheckField15DispatchThenSetup_0222de54(void);
void SetField_022274c0_022274c0(int v);

// USA: func_ov031_0222de24
ARM void CheckAndSetupTag21_0222de24(void) {
	if (GetField9AtIndex_0223c054(1) != 0) {
		return;
	}
	func_ov031_02225bf0();
	TailCallOffset94_02236878(0x15);
	SetField_022274c0_022274c0((int)CheckField15DispatchThenSetup_0222de54);
}

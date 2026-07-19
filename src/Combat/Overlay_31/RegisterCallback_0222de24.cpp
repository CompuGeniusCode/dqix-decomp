#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02225bf0(void);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern void CheckField15DispatchThenSetup_0222de54(void);

// USA: func_ov031_0222de24  (semantic: RegisterCallback_0222de24)
extern "C" ARM void func_ov031_0222de24(void) {
	if (func_ov031_0223c054(1) != 0) return;
	func_ov031_02225bf0();
	func_ov031_02236878(0x15);
	SetField_022274c0_022274c0((int)CheckField15DispatchThenSetup_0222de54);
}

#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_022334e8(void);

// USA: func_ov031_022334ac  (semantic: CheckTwoFlagsThenAdvance_022334ac)
extern "C" ARM void func_ov031_022334ac(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568(0);
	SetField_022274c0_022274c0((int)func_ov031_022334e8);
}

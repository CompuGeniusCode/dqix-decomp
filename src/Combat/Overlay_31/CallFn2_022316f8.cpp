#include <globaldefs.h>

extern int GetField16_02222e0c(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02231724(void);

// USA: func_ov031_022316f8  (semantic: CallFn2_022316f8)
extern "C" ARM void func_ov031_022316f8(void) {
	if (GetField16_02222e0c() != 0) {
		return;
	}
	func_ov031_022368e0();
	func_ov031_02236878(7);
	SetField_022274c0_022274c0((int)func_ov031_02231724);
}

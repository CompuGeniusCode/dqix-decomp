#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int);
ARM void SetField_022274c0_022274c0(int);
ARM void SetField18AndAdvance_02228f7c(void);

// USA: func_ov031_02228f54  (semantic: AdvanceUnlessField16Active_02228f54)
extern "C" ARM void func_ov031_02228f54(void) {
	if (GetField16_02222e0c() != 0) {
		return;
	}
	func_ov031_02236878(7);
	SetField_022274c0_022274c0((int)SetField18AndAdvance_02228f7c);
}

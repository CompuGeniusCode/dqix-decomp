#include <globaldefs.h>

extern int GetField16_02222e0c(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern void SetField_022274c0_022274c0(int);
extern void RegisterCallback_02231df8(void);

// USA: func_ov031_02231dcc  (semantic: CallFn2_02231dcc)
extern "C" ARM void func_ov031_02231dcc(void) {
	if (GetField16_02222e0c() != 0) {
		return;
	}
	func_ov031_022368e0();
	func_ov031_02236878(7);
	SetField_022274c0_022274c0((int)RegisterCallback_02231df8);
}

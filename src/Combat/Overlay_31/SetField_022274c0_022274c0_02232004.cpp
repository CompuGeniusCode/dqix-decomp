#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RegisterCallback_02231df8(void);

// USA: func_ov031_02232004  (semantic: RegisterCallback_02232004)
extern "C" ARM void func_ov031_02232004(void) {
	if (func_ov031_02237eb0() != 0) {
		return;
	}
	SetField_022274c0_022274c0((int)RegisterCallback_02231df8);
}

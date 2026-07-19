#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
ARM void CallStubPair_0222eef8(void);

// USA: func_ov031_02230ed0  (semantic: RegisterCallback_02230ed0)
extern "C" ARM void func_ov031_02230ed0(void) {
	if (func_ov031_02237eb0() != 0) {
		return;
	}
	SetField_022274c0_022274c0((int)CallStubPair_0222eef8);
}

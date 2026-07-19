#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
extern void CallStubPair_0222eef8(void);

// USA: func_ov031_0222eec4  (semantic: CheckTwoFlagsThenSetHandler_0222eec4)
extern "C" ARM void func_ov031_0222eec4(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	SetField_022274c0_022274c0((int)CallStubPair_0222eef8);
}

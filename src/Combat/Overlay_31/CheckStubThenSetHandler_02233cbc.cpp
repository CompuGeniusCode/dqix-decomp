#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
void SetField_022274c0_022274c0(int v);
void RegisterAndInit_02233ce0(void);

// USA: func_ov031_02233cbc  (semantic: CheckStubThenSetHandler_02233cbc)
extern "C" ARM void func_ov031_02233cbc(void) {
	if (func_ov031_0223c054(0) != 0) return;
	SetField_022274c0_022274c0((int)RegisterAndInit_02233ce0);
}

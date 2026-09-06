#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
extern void SetField_022274c0_022274c0(int);
extern void SetHandlerIfNotNegTwo_02228ef4(void);

// USA: func_ov031_02228eb8  (semantic: CheckFlagsThenSetHandler_02228eb8)
extern "C" ARM void func_ov031_02228eb8(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568(2);
	SetField_022274c0_022274c0((int)SetHandlerIfNotNegTwo_02228ef4);
}

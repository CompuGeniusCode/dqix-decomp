#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
extern void SetField_022274c0_022274c0(int);
extern void SetHandlerIfNotNegTwo_0222821c(void);

// USA: func_ov031_022281e0  (semantic: CheckFlagsThenSetHandler_022281e0)
extern "C" ARM void func_ov031_022281e0(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568(0);
	SetField_022274c0_022274c0((int)SetHandlerIfNotNegTwo_0222821c);
}

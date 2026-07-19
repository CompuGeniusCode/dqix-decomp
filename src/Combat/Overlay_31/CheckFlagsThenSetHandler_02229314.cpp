#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229350(void);

// USA: func_ov031_02229314  (semantic: CheckFlagsThenSetHandler_02229314)
extern "C" ARM void func_ov031_02229314(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568(0);
	SetField_022274c0_022274c0((int)func_ov031_02229350);
}

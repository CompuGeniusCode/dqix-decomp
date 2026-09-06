#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222b04c(void);

// USA: func_ov031_0222b010  (semantic: RunChecksAndSetHandler_0222b010)
extern "C" ARM void func_ov031_0222b010(void) {
	if (func_ov031_0223c054(1) != 0) return;
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_02223568(1);
	SetField_022274c0_022274c0((int)func_ov031_0222b04c);
}

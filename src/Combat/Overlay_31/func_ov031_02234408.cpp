#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
void SetField_022274c0_022274c0(int v);
void RunTwoStepInit_0223442c(void);

// USA: func_ov031_02234408
extern "C" ARM void func_ov031_02234408(void) {
	if (func_ov031_0223c054(0) != 0) return;
	SetField_022274c0_022274c0((int)RunTwoStepInit_0223442c);
}

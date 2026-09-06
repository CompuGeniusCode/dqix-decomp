#include <globaldefs.h>

int GetField16_02222e0c(void);
extern "C" void* func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222ac88(void);

// USA: func_ov031_0222ac5c  (semantic: AdvanceUnlessField16Active_0222ac5c)
extern "C" ARM void func_ov031_0222ac5c(void) {
	if (GetField16_02222e0c() != 0) return;
	func_ov031_022368e0();
	func_ov031_02236878(7);
	SetField_022274c0_022274c0((int)func_ov031_0222ac88);
}

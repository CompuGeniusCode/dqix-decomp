#include <globaldefs.h>

int GetField16_02222e0c(void);
extern "C" void func_ov031_02236878(int);
void SetField_022274c0_022274c0(int v);
extern "C" void func_ov031_0222e8f0(void);

// USA: func_ov031_0222e8c8  (semantic: AdvanceUnlessField16Active_0222e8c8)
extern "C" ARM void func_ov031_0222e8c8(void) {
	if (GetField16_02222e0c() != 0) return;
	func_ov031_02236878(6);
	SetField_022274c0_022274c0((int)func_ov031_0222e8f0);
}

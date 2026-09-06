#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int mask);
void SetField16IfMinusOne_02222e20(int v);

// USA: func_ov031_02229d30
extern "C" ARM void func_ov031_02229d30(void) {
	if (CheckMaskAgainstField32_0223d354(1) == 0) return;
	SetField16IfMinusOne_02222e20(0);
}

#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int mask);
void SetField16IfMinusOne_02222e20(int v);

// USA: func_ov031_02229b10
extern "C" ARM void func_ov031_02229b10(void) {
	if (CheckMaskAgainstField32_0223d354(1) == 0) return;
	SetField16IfMinusOne_02222e20(0);
}

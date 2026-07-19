#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);

// USA: func_ov031_0222e8a4  (semantic: CheckMaskAndSetField16_0222e8a4)
extern "C" ARM void func_ov031_0222e8a4(void) {
	if (CheckMaskAgainstField32_0223d354(1) == 0) return;
	SetField16IfMinusOne_02222e20(0);
}

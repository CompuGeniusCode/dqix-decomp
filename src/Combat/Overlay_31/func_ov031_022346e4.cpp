#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);

// USA: func_ov031_022346e4
extern "C" ARM void func_ov031_022346e4(void) {
	if (CheckMaskAgainstField32_0223d354(1)) {
		SetField16IfMinusOne_02222e20(1);
	}
	if (CheckMaskAgainstField32_0223d354(2) == 0) return;
	SetField16IfMinusOne_02222e20(0);
}

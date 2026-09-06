#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);
int IsKeyInputBit15Set_02231538(void);

// USA: func_ov031_022316bc
extern "C" ARM void func_ov031_022316bc(void) {
	if (CheckMaskAgainstField32_0223d354(2)) {
		SetField16IfMinusOne_02222e20(0);
		return;
	}
	if (IsKeyInputBit15Set_02231538() == 0) return;
	SetField16IfMinusOne_02222e20(0);
}

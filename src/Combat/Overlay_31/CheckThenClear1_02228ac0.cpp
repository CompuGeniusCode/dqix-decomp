#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);

// USA: func_ov031_02228ac0
ARM void CheckThenClear1_02228ac0(void) {
    if (CheckMaskAgainstField32_0223d354(1) == 0) {
        return;
    }
    SetField16IfMinusOne_02222e20(0);
}

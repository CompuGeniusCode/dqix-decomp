#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);

// USA: func_ov031_02228f30
ARM void CheckThenClear2_02228f30(void) {
    if (CheckMaskAgainstField32_0223d354(2) == 0) {
        return;
    }
    SetField16IfMinusOne_02222e20(0);
}

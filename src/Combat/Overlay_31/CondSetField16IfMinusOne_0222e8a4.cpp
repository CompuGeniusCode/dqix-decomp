#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int a);
void SetField16IfMinusOne_02222e20(int v);

// USA: func_ov031_0222e8a4
ARM void CondSetField16IfMinusOne_0222e8a4(void) {
    if (CheckMaskAgainstField32_0223d354(1)) {
        SetField16IfMinusOne_02222e20(0);
    }
}

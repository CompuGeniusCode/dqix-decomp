#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);
int IsKeyInputBit15Set_0222aa9c(void);

// USA: func_ov031_0222ac20
extern "C" ARM void func_ov031_0222ac20(void) {
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (IsKeyInputBit15Set_0222aa9c() == 0) return;
    SetField16IfMinusOne_02222e20(0);
}

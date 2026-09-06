#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void SetField16IfMinusOne_02222e20(int);
extern "C" int func_ov031_02231120(void);

// USA: func_ov031_022312a4
extern "C" ARM void func_ov031_022312a4(void) {
    if (CheckMaskAgainstField32_0223d354(2)) {
        SetField16IfMinusOne_02222e20(0);
        return;
    }
    if (func_ov031_02231120() == 0) return;
    SetField16IfMinusOne_02222e20(0);
}

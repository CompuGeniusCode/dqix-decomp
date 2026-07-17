#include <globaldefs.h>

int CheckMaskAgainstField32_0223d354(int);
void CallFunc020bc548AtOffset94_022368e0(void);
ARM void SetField16IfMinusOne_02222e20(int);

// USA: func_ov031_0223232c
ARM void RunIfFlag2_0223232c(void) {
    if (CheckMaskAgainstField32_0223d354(2) == 0) {
        return;
    }
    CallFunc020bc548AtOffset94_022368e0();
    SetField16IfMinusOne_02222e20(0);
}

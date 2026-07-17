#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
void CallFunc020bc548AtOffset94_022368e0(void);
void TailCallOffset94_02236878(int);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallbackThenSetup_0222ac88(void);

// USA: func_ov031_0222ac5c
ARM void AdvanceUnlessField16Active_0222ac5c(void) {
    if (GetField16_02222e0c() != 0) {
        return;
    }
    CallFunc020bc548AtOffset94_022368e0();
    TailCallOffset94_02236878(7);
    SetField_022274c0_022274c0((int)RegisterCallbackThenSetup_0222ac88);
}

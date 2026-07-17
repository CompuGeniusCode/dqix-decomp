#include <globaldefs.h>

int IsGlobal02290d10Set_02237eb0(void);
void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
void RunThreeSteps_02232844(void);

// USA: func_ov031_02233154
ARM void DispatchToStub_02233154(void) {
    if (IsGlobal02290d10Set_02237eb0() != 0) {
        return;
    }
    ClearField18_02222e80();
    SetField_022274c0_022274c0((int)RunThreeSteps_02232844);
}

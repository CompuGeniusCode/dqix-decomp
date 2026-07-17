#include <globaldefs.h>

int GetField16_02222e0c(void);
void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
void RunThreeSteps_02229378(void);

// USA: func_ov031_02229350
ARM void DispatchToStub_02229350(void) {
    if (GetField16_02222e0c() == -1) {
        return;
    }
    ClearField18_02222e80();
    SetField_022274c0_022274c0((int)RunThreeSteps_02229378);
}

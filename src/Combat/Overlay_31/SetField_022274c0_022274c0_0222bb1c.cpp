#include <globaldefs.h>

int GetField16_02222e0c(void);
void ClearField18_02222e80(void);
ARM void SetField_022274c0_022274c0(int);
void RunThreeSteps_0222bb44(void);

// USA: func_ov031_0222bb1c
ARM void DispatchToStub_0222bb1c(void) {
    if (GetField16_02222e0c() == -1) {
        return;
    }
    ClearField18_02222e80();
    SetField_022274c0_022274c0((int)RunThreeSteps_0222bb44);
}

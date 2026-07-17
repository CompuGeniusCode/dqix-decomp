#include <globaldefs.h>

int GetField16_02222e0c(void);
void TailCallOffset94_02236878(int);
ARM void SetField_022274c0_022274c0(int);
void SetField18AndAdvance_02229d7c(void);

// USA: func_ov031_02229d54
ARM void DispatchIfField16Zero_02229d54(void) {
    if (GetField16_02222e0c() != 0) {
        return;
    }
    TailCallOffset94_02236878(6);
    SetField_022274c0_022274c0((int)SetField18AndAdvance_02229d7c);
}

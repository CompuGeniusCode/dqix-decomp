#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
void RunTwoStepInit_0223442c(void);

// USA: func_ov031_02234408
ARM void DispatchToStub_02234408(void) {
    if (GetField9AtIndex_0223c054(0) != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)RunTwoStepInit_0223442c);
}

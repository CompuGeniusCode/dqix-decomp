#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
extern "C" void func_ov031_02223f6c(void);
void TailCallOffset94_02236878(int);
ARM void SetField_022274c0_022274c0(int);
void DispatchByField2aByte_0222d0e0(void);

// USA: func_ov031_0222d0b0
ARM void AdvanceUnlessFlag1_0222d0b0(void) {
    if (GetField9AtIndex_0223c054(1) != 0) {
        return;
    }
    func_ov031_02223f6c();
    TailCallOffset94_02236878(0x15);
    SetField_022274c0_022274c0((int)DispatchByField2aByte_0222d0e0);
}

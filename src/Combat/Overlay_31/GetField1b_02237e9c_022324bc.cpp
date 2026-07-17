#include <globaldefs.h>

ARM signed char GetField1b_02237e9c(void);
void TailCallOffset94_02236878(int);
void SetupField14_02237e58(void);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallbackIfNot_022324e8(void);

// USA: func_ov031_022324bc
ARM void AdvanceUnlessField1bActive_022324bc(void) {
    if (GetField1b_02237e9c() != 0) {
        return;
    }
    TailCallOffset94_02236878(6);
    SetupField14_02237e58();
    SetField_022274c0_022274c0((int)RegisterCallbackIfNot_022324e8);
}

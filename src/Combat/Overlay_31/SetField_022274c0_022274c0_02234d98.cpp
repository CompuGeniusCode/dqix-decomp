#include <globaldefs.h>

signed char GetField1b_02237e9c(void);
void TailCallOffset94_02236878(int);
void SetupField14_02237e58(void);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallbackIfNot_02234dc4(void);

// USA: func_ov031_02234d98
ARM void SetField274c0Unless1b_02234d98(void) {
    if (GetField1b_02237e9c() != 0) {
        return;
    }
    TailCallOffset94_02236878(6);
    SetupField14_02237e58();
    SetField_022274c0_022274c0((int)RegisterCallbackIfNot_02234dc4);
}

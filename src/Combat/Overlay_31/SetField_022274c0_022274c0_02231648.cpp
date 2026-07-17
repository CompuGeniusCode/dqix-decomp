#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
void CallIfField14Is1_02223568(int);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallbackIfField16Active_02231674(void);

// USA: func_ov031_02231648
ARM void AdvanceIfNotFlag0_02231648(void) {
    if (GetField9AtIndex_0223c054(0) != 0) {
        return;
    }
    CallIfField14Is1_02223568(1);
    SetField_022274c0_022274c0((int)RegisterCallbackIfField16Active_02231674);
}

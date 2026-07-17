#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
void RegisterAndInit_02233ce0(void);

// USA: func_ov031_02233cbc
ARM void DispatchToStub_02233cbc(void) {
    if (GetField9AtIndex_0223c054(0) != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)RegisterAndInit_02233ce0);
}

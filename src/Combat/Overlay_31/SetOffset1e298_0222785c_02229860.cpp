#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
ARM void SetOffset1e298_0222785c(int);
ARM void SetField_022274c0_022274c0(int);
void DispatchByMode_02229964(void);
void CallStubPair_02229890(void);

// USA: func_ov031_02229860
ARM void AdvanceUnlessFlag0_02229860(void) {
    if (GetField9AtIndex_0223c054(0) != 0) {
        return;
    }
    SetOffset1e298_0222785c((int)DispatchByMode_02229964);
    SetField_022274c0_022274c0((int)CallStubPair_02229890);
}

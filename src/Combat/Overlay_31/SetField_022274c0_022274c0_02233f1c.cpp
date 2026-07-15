#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
ARM void CallStubPair_02233f40(void);

// USA: func_ov031_02233f1c
ARM void DispatchToStub_02233f1c(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)CallStubPair_02233f40);
}

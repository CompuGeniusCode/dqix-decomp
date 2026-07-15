#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
ARM void CallStubPair_02231a9c(void);

// USA: func_ov031_02231a78
ARM void AdvanceIfNotFlag0_02231a78(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)CallStubPair_02231a9c);
}

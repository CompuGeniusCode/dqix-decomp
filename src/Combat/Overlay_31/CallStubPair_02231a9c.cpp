#include <globaldefs.h>

extern "C" void func_ov031_02231b5c(void);
extern "C" void func_ov031_02231aac(void);

// USA: func_ov031_02231a9c
ARM void CallStubPair_02231a9c(void) {
    func_ov031_02231b5c();
    func_ov031_02231aac();
}

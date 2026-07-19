#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern void SetOffset1e298_0222785c(int);
extern void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229964(void);
void CallStubPair_02229890(void);

// USA: func_ov031_02229860
extern "C" ARM void func_ov031_02229860(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    SetOffset1e298_0222785c((int)func_ov031_02229964);
    SetField_022274c0_022274c0((int)CallStubPair_02229890);
}

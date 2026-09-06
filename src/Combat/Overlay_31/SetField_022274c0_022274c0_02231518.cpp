#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0223130c(void);

// USA: func_ov031_02231518
ARM void RegisterCallbackIfNot_02231518(void) {
    if (func_ov031_02237eb0() != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)func_ov031_0223130c);
}

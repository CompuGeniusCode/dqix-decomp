#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02234b2c(void);

// USA: func_ov031_02234dc4
ARM void RegisterCallbackIfNot_02234dc4(void) {
    if (func_ov031_02237eb0() != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)func_ov031_02234b2c);
}

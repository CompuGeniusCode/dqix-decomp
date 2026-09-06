#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222a86c(void);

// USA: func_ov031_0222a848
ARM void AdvanceIfNotFlag0_0222a848(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    SetField_022274c0_022274c0((int)func_ov031_0222a86c);
}

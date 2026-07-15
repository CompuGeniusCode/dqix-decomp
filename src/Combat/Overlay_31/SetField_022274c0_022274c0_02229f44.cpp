#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02229f70(void);

// USA: func_ov031_02229f44
ARM void AdvanceIfNotFlag0_02229f44(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    func_ov031_02223568(3);
    SetField_022274c0_022274c0((int)func_ov031_02229f70);
}

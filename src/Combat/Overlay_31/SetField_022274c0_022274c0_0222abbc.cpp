#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_02223568(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222abe8(void);

// USA: func_ov031_0222abbc
ARM void AdvanceIfNotFlag0_0222abbc(void) {
    if (func_ov031_0223c054(0) != 0) {
        return;
    }
    func_ov031_02223568(1);
    SetField_022274c0_022274c0((int)func_ov031_0222abe8);
}

#include <globaldefs.h>

ARM signed char GetField1b_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0222d6dc(void);

// USA: func_ov031_0222d6b0
ARM void AdvanceUnlessField1bActive_0222d6b0(void) {
    if (GetField1b_02237e9c() != 0) {
        return;
    }
    func_ov031_02236878(6);
    func_ov031_02237e58();
    SetField_022274c0_022274c0((int)func_ov031_0222d6dc);
}

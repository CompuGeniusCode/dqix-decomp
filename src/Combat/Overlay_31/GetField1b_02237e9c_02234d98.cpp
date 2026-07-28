#include <globaldefs.h>

ARM signed char GetField1b_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_02237e58(void);
ARM void SetField_022274c0_022274c0(int);
ARM void RegisterCallbackIfNot_02234dc4(void);

// USA: func_ov031_02234d98  (semantic: AdvanceUnlessField1bActive_02234d98)
extern "C" ARM void func_ov031_02234d98(void) {
    if (GetField1b_02237e9c() != 0) {
        return;
    }
    func_ov031_02236878(6);
    func_ov031_02237e58();
    SetField_022274c0_022274c0((int)RegisterCallbackIfNot_02234dc4);
}

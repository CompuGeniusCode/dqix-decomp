#include <globaldefs.h>

signed char GetField1b_02237e9c(void);
extern "C" void func_ov031_02236878(int);
extern unsigned char data_ov031_02290c58;
extern "C" void func_ov031_02237e58(void);
void SetField_022274c0_022274c0(int);
void RegisterCallbackIfNot_02228960(void);

// USA: func_ov031_02228910  (semantic: SetupOrArmHandler_02228910)
extern "C" ARM void func_ov031_02228910(void) {
    signed char v = GetField1b_02237e9c();
    if (v != 0) {
        if (v != 1) return;
        func_ov031_02236878(0xe);
        data_ov031_02290c58 = 1;
    } else {
        func_ov031_02236878(7);
    }
    func_ov031_02237e58();
    SetField_022274c0_022274c0((int)RegisterCallbackIfNot_02228960);
}

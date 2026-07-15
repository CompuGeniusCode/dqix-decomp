#include <globaldefs.h>

ARM int GetField16_02222e0c(void);
extern "C" void func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_0223130c(void);

// USA: func_ov031_022312e0
ARM void AdvanceUnlessField16Active_022312e0(void) {
    if (GetField16_02222e0c() != 0) {
        return;
    }
    func_ov031_022368e0();
    func_ov031_02236878(7);
    SetField_022274c0_022274c0((int)func_ov031_0223130c);
}

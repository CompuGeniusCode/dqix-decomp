#include <globaldefs.h>

ARM void SetField18_02222e98(void);
extern "C" void func_ov031_0223c278(int);
ARM void SetField_022274c0_022274c0(int);
extern "C" void func_ov031_02228b2c(void);

// USA: func_ov031_02228b0c
ARM void RegisterCallback_02228b0c(void) {
    SetField18_02222e98();
    func_ov031_0223c278(8);
    SetField_022274c0_022274c0((int)func_ov031_02228b2c);
}

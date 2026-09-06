#include <globaldefs.h>

void SetField18_02222e98(void);
extern "C" void func_ov031_0223c278(int);
void SetField_022274c0_022274c0(int);
void *RegisterCallback120_022277e4(void);
extern unsigned char data_ov031_02290c7c;
void RunSetupAndRegisterHandler_0222acc0(void);

// USA: func_ov031_0222ac88  (semantic: RunSetupAndRegisterHandler_0222ac88)
extern "C" ARM void func_ov031_0222ac88(void) {
    if (data_ov031_02290c7c == 0) {
        RegisterCallback120_022277e4();
    }
    SetField18_02222e98();
    func_ov031_0223c278(8);
    SetField_022274c0_022274c0((int)RunSetupAndRegisterHandler_0222acc0);
}

#include <globaldefs.h>

extern "C" void func_ov031_0223c278(int);
extern "C" void func_ov031_0222d0b0(void);
void SetField_022274c0_022274c0(int v);

// USA: func_ov031_0222d094
ARM void SetupHandlerA_0222d094(void) {
    func_ov031_0223c278(8);
    SetField_022274c0_022274c0((int)func_ov031_0222d0b0);
}

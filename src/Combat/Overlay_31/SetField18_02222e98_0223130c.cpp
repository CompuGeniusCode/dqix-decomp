#include <globaldefs.h>

ARM void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int);
ARM void SetField_022274c0_022274c0(int);
void GateThenConditionalSetup_0223132c(void);

// USA: func_ov031_0223130c
ARM void RegisterCallback_0223130c(void) {
    SetField18_02222e98();
    RegisterHandlerSlot_0223c278(8);
    SetField_022274c0_022274c0((int)GateThenConditionalSetup_0223132c);
}

#include <globaldefs.h>

ARM void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int);
ARM void SetField_022274c0_022274c0(int);
void RunPending_022287f4(void);

// USA: func_ov031_022287d4
ARM void RegisterCallback_022287d4(void) {
    SetField18_02222e98();
    RegisterHandlerSlot_0223c278(8);
    SetField_022274c0_022274c0((int)RunPending_022287f4);
}

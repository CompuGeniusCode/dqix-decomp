#include <globaldefs.h>

void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int a);
void SetField_022274c0_022274c0(void* fn);
void RunPending_0222a058(void);

// USA: func_ov031_0222a038
ARM void SetFlag18ThenTransition_0222a038(void) {
    SetField18_02222e98();
    RegisterHandlerSlot_0223c278(8);
    SetField_022274c0_022274c0((void*)RunPending_0222a058);
}

#include <globaldefs.h>

void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int a);
void SetField_022274c0_022274c0(void* fn);
void RunGateThenSetup_0222a5b8(void);

// USA: func_ov031_0222a598
ARM void SetFlag18ThenTransition_0222a598(void) {
    SetField18_02222e98();
    RegisterHandlerSlot_0223c278(8);
    SetField_022274c0_022274c0((void*)RunGateThenSetup_0222a5b8);
}

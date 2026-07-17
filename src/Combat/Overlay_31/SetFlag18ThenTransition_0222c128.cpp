#include <globaldefs.h>

void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int a);
void SetField_022274c0_022274c0(void* fn);
void CheckFlag54ThenSetup_0222c148(void);

// USA: func_ov031_0222c128
ARM void SetFlag18ThenTransition_0222c128(void) {
    SetField18_02222e98();
    RegisterHandlerSlot_0223c278(8);
    SetField_022274c0_022274c0((void*)CheckFlag54ThenSetup_0222c148);
}

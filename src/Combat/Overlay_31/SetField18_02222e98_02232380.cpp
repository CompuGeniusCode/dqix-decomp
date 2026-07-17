#include <globaldefs.h>

ARM void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int);
ARM void SetField_022274c0_022274c0(int);
void RegisterCallback_022323a0(void);

// USA: func_ov031_02232380
ARM void RegisterCallback_02232380(void) {
	SetField18_02222e98();
	RegisterHandlerSlot_0223c278(8);
	SetField_022274c0_022274c0((int)RegisterCallback_022323a0);
}

#include <globaldefs.h>

extern unsigned char data_ov031_02290c7c;
extern "C" void *RegisterCallback120_022277e4(void);
extern void SetField18_02222e98(void);
void RegisterHandlerSlot_0223c278(int);
extern void SetField_022274c0_022274c0(int);
void RunSetupAndRegisterHandler_0222acc0(void);

// USA: func_ov031_0222ac88
ARM void RegisterCallbackThenSetup_0222ac88(void) {
	if (data_ov031_02290c7c == 0) {
		RegisterCallback120_022277e4();
	}
	SetField18_02222e98();
	RegisterHandlerSlot_0223c278(8);
	SetField_022274c0_022274c0((int)RunSetupAndRegisterHandler_0222acc0);
}

#include <globaldefs.h>

extern void SetField18_02222e98(void);
extern int TailCallForward_0223e2e0(int, void*);
int RegisterHandlerSlot_0223c278(int);
extern void SetField_022274c0_022274c0(int);
extern unsigned char data_ov031_02290c80;
void RegisterCallback_0222b22c(void);

// USA: func_ov031_0222b1f0
ARM void RunFieldDispatchThenSetHandler_0222b1f0(void) {
	SetField18_02222e98();
	void* field4 = *(void**)((&data_ov031_02290c80) + 4);
	if (field4 != NULL) {
		TailCallForward_0223e2e0(1, field4);
	}
	RegisterHandlerSlot_0223c278(8);
	SetField_022274c0_022274c0((int)RegisterCallback_0222b22c);
}

#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
extern unsigned char data_ov031_02290cac;
int TailCall_02222ddc(void);
void RegisterSlotEntry_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
void RunChecksAndSetHandler_022313a0(void);

// USA: func_ov031_0223132c
ARM void GateThenConditionalSetup_0223132c(void) {
	if (GetField9AtIndex_0223c054(1) != 0) return;
	if (data_ov031_02290cac == 0) {
		TailCall_02222ddc();
	}
	if (data_ov031_02290cac == 0) {
		RegisterSlotEntry_0223c078(3, 1, 1, 8);
	}
	RegisterSlotEntry_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_022313a0);
}

#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
int TailCall_02222ddc(void);
void RegisterSlotEntry_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
void RunChecksAndSetHandler_0222a61c(void);

extern unsigned char data_ov031_02290c74;

// USA: func_ov031_0222a5b8
ARM void RunGateThenSetup_0222a5b8(void) {
	if (GetField9AtIndex_0223c054(1) != 0) return;
	TailCall_02222ddc();
	if ((&data_ov031_02290c74)[1] == 0) {
		RegisterSlotEntry_0223c078(3, 1, 1, 8);
	}
	RegisterSlotEntry_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_0222a61c);
}

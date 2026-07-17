#include <globaldefs.h>

extern unsigned char data_ov031_02290c58;

int GetField9AtIndex_0223c054(int);
int RegisterSlotEntry_0223c078(int, int, int, int);
void RunChecksAndSetHandler_02228858(void);
extern "C" int TailCall_02222ddc(void);
extern "C" void SetField_022274c0_022274c0(int);

// USA: func_ov031_022287f4
ARM void RunPending_022287f4(void) {
	int r = GetField9AtIndex_0223c054(1);
	if (r != 0) return;
	TailCall_02222ddc();
	if (data_ov031_02290c58 == 0) {
		RegisterSlotEntry_0223c078(3, 1, 1, 8);
	}
	RegisterSlotEntry_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_02228858);
}

#include <globaldefs.h>

extern unsigned char data_ov031_02290c6c;

int GetField9AtIndex_0223c054(int);
int RegisterSlotEntry_0223c078(int, int, int, int);
void RunChecksAndSetHandler_0222a0bc(void);
extern "C" int TailCall_02222ddc(void);
extern "C" void SetField_022274c0_022274c0(int);

// USA: func_ov031_0222a058
ARM void RunPending_0222a058(void) {
	int r = GetField9AtIndex_0223c054(1);
	if (r != 0) return;
	TailCall_02222ddc();
	if (data_ov031_02290c6c == 0) {
		RegisterSlotEntry_0223c078(3, 1, 1, 8);
	}
	RegisterSlotEntry_0223c078(3, 0, 0x15, 8);
	SetField_022274c0_022274c0((int)RunChecksAndSetHandler_0222a0bc);
}

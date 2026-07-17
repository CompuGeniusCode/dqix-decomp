#include <globaldefs.h>

int GetField9AtIndex_0223c054(int);
struct Inner0222c148 { unsigned char pad[0x54]; unsigned char field54; };
struct Struct02290c8c { int field0; Inner0222c148 *field4; };
extern Struct02290c8c data_ov031_02290c8c;
int TailCall_02222ddc(void);
extern void SetField18_02222e98(void);
void RegisterSlotEntry_0223c078(int, int, int, int);
extern void SetField_022274c0_022274c0(int);
void RunFieldChecksAndDispatch_0222c1b8(void);

// USA: func_ov031_0222c148
ARM void CheckFlag54ThenSetup_0222c148(void) {
	if (GetField9AtIndex_0223c054(1) != 0) return;
	if (data_ov031_02290c8c.field4->field54 != 0) {
		TailCall_02222ddc();
	} else {
		SetField18_02222e98();
	}
	RegisterSlotEntry_0223c078(3, 1, 1, 8);
	RegisterSlotEntry_0223c078(3, 0, 0x1d, 8);
	SetField_022274c0_022274c0((int)RunFieldChecksAndDispatch_0222c1b8);
}

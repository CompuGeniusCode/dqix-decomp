#include <globaldefs.h>

int GetField16_02222e0c(void);
void SetField16_02222e40(int v);
extern "C" int func_ov031_02236878(int index);
int TailCallLookup_02229748(void);
void SetField_022274c0_022274c0(int v);
void SetField18AndAdvance_02229528(void);

struct LocalBuf02229484 { int field0; int field4; char pad[0xc]; };
extern "C" void func_ov031_0221ae00(LocalBuf02229484* buf);

struct IdxFlag02229484 { unsigned char idx; unsigned char flag1; };
extern IdxFlag02229484 data_ov031_02290c5c;

#pragma optimize_for_size off
// USA: func_ov031_02229484
ARM void func_ov031_02229484(void) {
	int mode = GetField16_02222e0c();
	switch (mode) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1: {
		LocalBuf02229484 buf;
		func_ov031_0221ae00(&buf);
		if (data_ov031_02290c5c.idx != 0) {
			int field4 = buf.field4;
			int field0 = buf.field0;
			if (field4 == 0 && field0 == 0) {
				func_ov031_02236878(9);
				SetField16_02222e40(-1);
				return;
			}
		}
		func_ov031_02236878(6);
		TailCallLookup_02229748();
		data_ov031_02290c5c.flag1 = 1;
		break;
	}
	default:
		return;
	}
	SetField_022274c0_022274c0((int)SetField18AndAdvance_02229528);
}

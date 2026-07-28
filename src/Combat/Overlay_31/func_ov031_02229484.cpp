#include <globaldefs.h>

int GetField16_02222e0c(void);
void SetField16_02222e40(int v);
extern "C" void func_ov031_0221ae00(void* buf);
extern "C" int func_ov031_02236878(int index);
int TailCallLookup_02229748(void);
void SetField_022274c0_022274c0(int fn);
void SetField18AndAdvance_02229528(void);

struct Buf0221ae00_02229484 { unsigned long long u0; unsigned long long u1; int pad; };

struct DataC5c_02229484 { unsigned char idx; unsigned char flag; };
extern DataC5c_02229484 data_ov031_02290c5c;

// USA: func_ov031_02229484  (semantic: DispatchByField16AndActivate_02229484)
#pragma optimize_for_size off
extern "C" ARM void func_ov031_02229484(void) {
	int f16 = GetField16_02222e0c();
	switch (f16) {
	case 0:
		func_ov031_02236878(7);
		break;
	case 1: {
		Buf0221ae00_02229484 buf;
		func_ov031_0221ae00(&buf);
		if (data_ov031_02290c5c.idx != 0 && buf.u0 == 0) {
			func_ov031_02236878(9);
			SetField16_02222e40(-1);
			return;
		}
		func_ov031_02236878(6);
		TailCallLookup_02229748();
		data_ov031_02290c5c.flag = 1;
		break;
	}
	default:
		return;
	}
	SetField_022274c0_022274c0((int)SetField18AndAdvance_02229528);
}

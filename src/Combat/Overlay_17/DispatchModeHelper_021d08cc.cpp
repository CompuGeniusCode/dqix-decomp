#include <globaldefs.h>

extern "C" void func_ov017_0219949c(int a, int b, unsigned char c, unsigned char d, signed char e);
extern "C" void func_ov017_02199578(int a, int b, unsigned char c, unsigned char d, signed char e);

struct LocalEvt021d08cc {
	unsigned char pad0[4];
	unsigned char field4;
	unsigned char field5;
	unsigned char field6;
	signed char field7;
};

// USA: func_ov017_021d08cc
ARM void DispatchModeHelper_021d08cc(int origParam0, LocalEvt021d08cc* evt, int unused2, int table) {
	if (evt->field6 == 0) {
		func_ov017_0219949c(table, origParam0, evt->field4, evt->field5, evt->field7);
	} else if (evt->field6 == 1) {
		func_ov017_02199578(table, origParam0, evt->field4, evt->field5, evt->field7);
	}
}

#include <globaldefs.h>

extern "C" int func_ov023_021e29d0(void*);
extern "C" int func_02012444(void*, int);
extern int data_02114e30;

// USA: func_ov006_02159bb0
ARM int ClassifyCombatState_02159bb0(char* obj) {
	int r4 = 0;
	int r5 = 0;
	int r6 = 0;
	int r7 = 0;
	int result = func_ov023_021e29d0(obj + 0x100);
	if (result >= 0) {
		if (result == 0x41) r4 = 1;
		r5 = (result == 0x42);
		r6 = (result == 0x13);
		r7 = (result == 0x26);
	} else {
		if (func_02012444(&data_02114e30, 4) != 0) r6 = 1;
		if (func_02012444(&data_02114e30, 0x300) != 0) r7 = 1;
	}
	if (r6) return 1;
	if (r4) return 2;
	if (r5) return 3;
	if (r7) return 4;
	return 0;
}

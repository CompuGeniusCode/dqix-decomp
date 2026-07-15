#include <globaldefs.h>

extern "C" int func_ov003_0217bdb8(void* p);

// USA: func_ov003_02173490
ARM void InitCombatFields_02173490(unsigned char* obj) {
	int ok = (func_ov003_0217bdb8(obj + 0x1e0) != 0);
	if (!ok) return;
	obj[0xcc] = 1;
	obj[0xd4] = 0;
	obj[0xec] = 4;
	obj[0xee] = 0;
	obj[0xed] = 4;
	obj[0xef] = 0;
}

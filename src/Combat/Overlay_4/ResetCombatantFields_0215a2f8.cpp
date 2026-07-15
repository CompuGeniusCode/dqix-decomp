#include <globaldefs.h>

// USA: func_ov004_0215a2f8
ARM void* ResetCombatantFields_0215a2f8(void* obj) {
	*(short*)((char*)obj + 0x6c) = -1;
	*(char*)((char*)obj + 0x6e) = 0;
	*(char*)((char*)obj + 0x6f) = 0;
	*(char*)((char*)obj + 0x70) = -1;
	*(int*)((char*)obj + 0x74) = -1;
	*(int*)((char*)obj + 0x78) = 0;
	return obj;
}

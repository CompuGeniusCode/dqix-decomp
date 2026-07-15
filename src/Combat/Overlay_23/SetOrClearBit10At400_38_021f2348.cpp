#include <globaldefs.h>

// USA: func_ov023_021f2348
ARM void SetOrClearBit10At400_38_021f2348(void* obj, int flag) {
	obj = (char*)obj + 0x400;
	int v;
	if (flag != 0) v = *(volatile unsigned short*)((char*)obj + 0x38) | 0x400;
	else v = *(volatile unsigned short*)((char*)obj + 0x38) & ~0x400;
	*(unsigned short*)((char*)obj + 0x38) = v;
}

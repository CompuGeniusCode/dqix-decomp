#include <globaldefs.h>

// USA: func_ov017_021a932c
ARM void SetBoolFieldAt20_021a932c(void* obj, int val) {
	if (val)
		val = 1;
	*(int*)((char*)obj + 0x14) = val;
}

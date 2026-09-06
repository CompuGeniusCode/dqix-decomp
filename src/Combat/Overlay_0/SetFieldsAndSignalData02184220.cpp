#include <globaldefs.h>

extern int data_ov000_02184220;

// USA: func_ov000_02160d80
ARM void SetFieldsAndSignalData02184220(void* p, int val) {
	*(int*)((char*)p + 0xea8) = val;
	*(int*)((char*)p + 0xeac) = 0;
	data_ov000_02184220 = 1;
}

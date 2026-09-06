#include <globaldefs.h>

// USA: func_ov006_021591c4
ARM int GetArrEntry_021591c4_021591c4(void* p) {
	int result = 0;
	short idx = *(short*)((char*)p + 0x300 + 0x62) - 0x5b;
	if (idx >= 0) {
		int* arr = *(int**)((char*)p + 0x4c);
		result = arr[idx];
	}
	return result;
}

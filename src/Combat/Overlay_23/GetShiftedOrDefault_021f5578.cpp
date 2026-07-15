#include <globaldefs.h>

extern "C" unsigned int* func_ov023_021f5534(void* a, void* b);

// USA: func_ov023_021f5578
ARM int GetShiftedOrDefault_021f5578(void* a, void* b, int def) {
	unsigned int* p = func_ov023_021f5534(a, b);
	if (p != 0) def = *p >> 0x1a;
	return def;
}

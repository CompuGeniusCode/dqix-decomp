#include <globaldefs.h>

// USA: func_ov017_0219219c  (semantic: GetOffsetForIndex_0219219c)
extern "C" ARM void* func_ov017_0219219c(char* base, int idx) {
	int inRange1 = (idx >= 0 && idx <= 3);
	if (inRange1) {
		return base + 0x2dc + 0x3400 + idx;
	}
	int inRange2 = (idx >= 0xc0 && idx <= 0xc7);
	if (inRange2) {
		return base + 0xe1 + 0x3600 + (idx - 0xc0);
	}
	return NULL;
}

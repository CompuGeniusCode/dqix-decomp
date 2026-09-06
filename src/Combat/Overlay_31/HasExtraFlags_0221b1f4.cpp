#include <globaldefs.h>
#include "System/Memory.h"

int CheckRange_0221b258(unsigned char* p);

// USA: func_ov031_0221b1f4  (semantic: HasExtraFlags_0221b1f4)
#pragma optimize_for_size off
extern "C" ARM int func_ov031_0221b1f4(unsigned char* a, unsigned char* b) {
	if (!CheckRange_0221b258(a)) {
		return 0;
	}
	unsigned int va;
	unsigned int vb;
	VectorizedInvertedMemcpy(a, &va, 4);
	VectorizedInvertedMemcpy(b, &vb, 4);
	return (va & ~vb) != 0;
}

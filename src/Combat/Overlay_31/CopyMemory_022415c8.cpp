#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_022415c8
ARM void CopyMemory_022415c8(void* dst, const void* src, unsigned int length) {
	VectorizedInvertedMemcpy(src, dst, length);
}

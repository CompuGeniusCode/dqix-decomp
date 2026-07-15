#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_0223fb74
ARM void CopyBytesSwapped_0223fb74(void* dst, const void* src, unsigned int length) {
	VectorizedInvertedMemcpy(src, dst, length);
}

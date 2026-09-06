#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_0220ab94
ARM void CopyForward_0220ab94(void* dst, const void* src, unsigned int length) {
	VectorizedInvertedMemcpy(src, dst, length);
}

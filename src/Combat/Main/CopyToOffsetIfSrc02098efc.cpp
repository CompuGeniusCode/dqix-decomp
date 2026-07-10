#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02098efc
ARM void CopyToOffsetIfSrc02098efc(char* obj, int offset, const void* src, unsigned int length) {
    if (src == NULL) return;
    VectorizedInvertedMemcpy(src, obj + offset, length);
}

#include <globaldefs.h>

#pragma optimize_for_size off
#include "System/Memory.h"

// USA: func_ov031_0221e51c  (semantic: CopyToDest_0221e51c)
extern "C" THUMB void func_ov031_0221e51c(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
}

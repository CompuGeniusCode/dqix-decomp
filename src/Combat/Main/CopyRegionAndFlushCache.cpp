#include <globaldefs.h>
#include "System/Memory.h"

void CleanInvalidateDataCacheRange(int addr, int size);

// USA: func_020d8524
ARM unsigned int CopyRegionAndFlushCache(void* dst, const void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    CleanInvalidateDataCacheRange((int)dst, length);
    return length;
}

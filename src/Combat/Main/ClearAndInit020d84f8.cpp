#include <globaldefs.h>
#include "System/Memory.h"

void CleanInvalidateCacheRange(const void* addr, unsigned int size);

// USA: func_020d84f8
ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    CleanInvalidateCacheRange((const void*)((int)obj), len);
    return len;
}

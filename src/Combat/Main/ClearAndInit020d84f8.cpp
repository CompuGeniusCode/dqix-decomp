#include <globaldefs.h>
#include "System/Memory.h"

void CleanInvalidateDataCacheRange(int addr, int len);

// USA: func_020d84f8
ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    CleanInvalidateDataCacheRange((int)obj, len);
    return len;
}

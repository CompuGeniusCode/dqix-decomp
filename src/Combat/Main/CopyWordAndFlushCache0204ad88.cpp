#include <globaldefs.h>
#include "std_library_functions.h"

void CleanInvalidateDataCacheRange(int addr, int size);

// USA: func_0204ad88
ARM void CopyWordAndFlushCache0204ad88(void* a, void* b) {
    memcpy((char*)a + 8, (char*)b + 0xc, 4);
    CleanInvalidateDataCacheRange((int)((char*)b + 0x10), *(int*)((char*)a + 8));
}

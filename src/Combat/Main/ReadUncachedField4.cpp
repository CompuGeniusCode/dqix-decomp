#include <globaldefs.h>

void InvalidateDataCacheRange(int addr, int size);
extern int* data_021142c0;

// USA: func_020d29f4
ARM int ReadUncachedField4(void) {
    InvalidateDataCacheRange((int)(data_021142c0 + 1), 4);
    return data_021142c0[1];
}

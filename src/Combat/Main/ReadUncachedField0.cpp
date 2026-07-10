#include <globaldefs.h>

void InvalidateDataCacheRange(int addr, int size);
extern int* data_021142c0;

// USA: func_020d2a20
ARM int ReadUncachedField0(void) {
    InvalidateDataCacheRange((int)data_021142c0, 4);
    return data_021142c0[0];
}

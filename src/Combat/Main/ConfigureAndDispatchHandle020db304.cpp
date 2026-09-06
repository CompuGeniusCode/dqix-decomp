#include <globaldefs.h>

int GetObjectValue020db2dc(int a, int b);
void DMAMemsetSynchronous(int, unsigned int, unsigned int, unsigned int);
void CleanInvalidateCacheRange(const void* addr, unsigned int size);
void CleanCacheRange(const void* addr, unsigned int size);

typedef void (*DispatchFn020db304)(int, int, int);
extern DispatchFn020db304 data_020f2904[];

// USA: func_020db304
ARM void ConfigureAndDispatchHandle020db304(int param0, int param1) {
    int handle = GetObjectValue020db2dc(param0, param1);
    DMAMemsetSynchronous(3, handle, 0xc0, 0x400);
    CleanInvalidateCacheRange((const void*)(handle), 0x400);
    data_020f2904[param1](handle, 0, 0x400);
    CleanCacheRange((const void*)(handle), 0x400);
}

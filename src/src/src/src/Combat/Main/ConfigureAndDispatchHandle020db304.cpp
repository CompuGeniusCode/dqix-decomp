#include <globaldefs.h>

int GetObjectValue020db2dc(int a, int b);
extern "C" void func_020c9c0c(int, int, int, int);
void CleanInvalidateDataCacheRange(int addr, int size);
void CleanDataCacheRange(int addr, int size);

typedef void (*DispatchFn020db304)(int, int, int);
extern DispatchFn020db304 data_020f2904[];

// USA: func_020db304
ARM void ConfigureAndDispatchHandle020db304(int param0, int param1) {
    int handle = GetObjectValue020db2dc(param0, param1);
    func_020c9c0c(3, handle, 0xc0, 0x400);
    CleanInvalidateDataCacheRange(handle, 0x400);
    data_020f2904[param1](handle, 0, 0x400);
    CleanDataCacheRange(handle, 0x400);
}

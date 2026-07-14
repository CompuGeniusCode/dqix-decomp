#include <globaldefs.h>
#include "std_library_functions.h"

void CleanDataCacheRange(int addr, int size);
void CleanInvalidateDataCacheRange(int addr, int size);
int TransferSubBg1CharData(int arg0, int arg1, unsigned int arg2);
unsigned int GetSubBg1ScreenBaseAddr(void);

// USA: func_020a64e8
#pragma opt_common_subs off
ARM void ResetSubBg1AndClearCache020a64e8(void) {
    unsigned char buffer[0x20];
    *(volatile int*)0x4001014 = 0;
    memset(buffer, 0, 0x20);
    CleanDataCacheRange((int)buffer, 0x20);
    CleanInvalidateDataCacheRange((int)buffer, 0x20);
    TransferSubBg1CharData((int)buffer, 0, 0x20);
    memset((void*)GetSubBg1ScreenBaseAddr(), 0, 0x800);
}

#include <globaldefs.h>

void CleanInvalidateDataCacheRange(int addr, int size);
extern int data_021052b4;
extern int data_021056b4;

// USA: func_0203bd88
ARM void CleanInvalidateOamBuffers0203bd88() {
    CleanInvalidateDataCacheRange((int)&data_021052b4, 0x400);
    CleanInvalidateDataCacheRange((int)&data_021056b4, 0x400);
}

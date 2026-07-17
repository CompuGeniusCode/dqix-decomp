#include <globaldefs.h>

int GetData02104304Field4();
void ResetIfNonNeg_021db2e4(volatile int* p);

// USA: func_ov023_021dcdf4
ARM void ResetPendingSlotsAndFlags_021dcdf4(void* obj) {
    GetData02104304Field4();
    if (*((unsigned char*)obj + 0x776)) {
        ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x734));
        for (int i = 0; i < 7; i++) {
            ResetIfNonNeg_021db2e4((volatile int*)((char*)obj + 0x738 + i * 4));
        }
        *(int*)((char*)obj + 0x754) = 0;
        *(unsigned short*)((char*)obj + 0x774) |= 1;
    }
    *(short*)((char*)obj + 0x772) = -1;
    *(short*)((char*)obj + 0x770) = -2;
    *(char*)((char*)obj + 0x779) = -1;
    *(unsigned short*)((char*)obj + 0x774) &= ~4;
    *(unsigned short*)((char*)obj + 0x774) &= ~0x2000;
}

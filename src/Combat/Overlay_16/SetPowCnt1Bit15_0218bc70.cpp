#include <globaldefs.h>

// USA: func_ov016_0218bc70
ARM int SetPowCnt1Bit15_0218bc70(int enable) {
    volatile unsigned short* powcnt = (volatile unsigned short*)0x4000304;
    int value = (*powcnt & ~0x8000) | (enable << 15);
    *powcnt = value;
    return value;
}

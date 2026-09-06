#include <globaldefs.h>

// USA: func_ov011_02186360
ARM int SetBg7Priority_02186360(int priority) {
    volatile unsigned short* bg7cnt = (volatile unsigned short*)0x400100e;
    int value = (*bg7cnt & ~3) | priority;
    *bg7cnt = value;
    return value;
}

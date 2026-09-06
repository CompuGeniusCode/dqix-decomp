#include <globaldefs.h>

// USA: func_ov011_0218637c
ARM int SetBg6Priority_0218637c(int priority) {
    volatile unsigned short* bg6cnt = (volatile unsigned short*)0x400100c;
    int value = (*bg6cnt & ~3) | priority;
    *bg6cnt = value;
    return value;
}

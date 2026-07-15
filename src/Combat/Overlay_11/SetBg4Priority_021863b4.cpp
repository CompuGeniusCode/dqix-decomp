#include <globaldefs.h>

// USA: func_ov011_021863b4
ARM int SetBg4Priority_021863b4(int priority) {
    volatile unsigned short* bg4cnt = (volatile unsigned short*)0x4001008;
    int value = (*bg4cnt & ~3) | priority;
    *bg4cnt = value;
    return value;
}

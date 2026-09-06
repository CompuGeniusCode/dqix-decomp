#include <globaldefs.h>

// USA: func_ov011_021863ec
ARM int SetBg2Priority_021863ec(int priority) {
    volatile unsigned short* bg2cnt = (volatile unsigned short*)0x400000c;
    int value = (*bg2cnt & ~3) | priority;
    *bg2cnt = value;
    return value;
}

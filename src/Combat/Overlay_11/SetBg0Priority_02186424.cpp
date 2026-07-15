#include <globaldefs.h>

// USA: func_ov011_02186424
ARM int SetBg0Priority_02186424(int priority) {
    volatile unsigned short* bg0cnt = (volatile unsigned short*)0x4000008;
    int value = (*bg0cnt & ~3) | priority;
    *bg0cnt = value;
    return value;
}

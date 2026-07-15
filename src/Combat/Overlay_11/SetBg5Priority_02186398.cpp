#include <globaldefs.h>

// USA: func_ov011_02186398
ARM int SetBg5Priority_02186398(int priority) {
    volatile unsigned short* bg5cnt = (volatile unsigned short*)0x400100a;
    int value = (*bg5cnt & ~3) | priority;
    *bg5cnt = value;
    return value;
}

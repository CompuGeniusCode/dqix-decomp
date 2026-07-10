#include <globaldefs.h>

// USA: func_020c2c38
ARM long long GetDivResult64(void) {
    volatile unsigned short* cnt = (volatile unsigned short*)0x4000280;
    while (*cnt & 0x8000) ;
    return *(long long*)0x40002a0;
}

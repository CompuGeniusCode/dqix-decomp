#include <globaldefs.h>

extern unsigned short data_02111224[];

// USA: func_020c3a4c
ARM void ResetVramAndClearState(void) {
    data_02111224[0] = 0;
    data_02111224[1] = 0;
    data_02111224[2] = 0;
    data_02111224[3] = 0;
    data_02111224[4] = 0;
    data_02111224[5] = 0;
    data_02111224[6] = 0;
    data_02111224[7] = 0;
    data_02111224[8] = 0;
    data_02111224[9] = 0;
    data_02111224[10] = 0;
    data_02111224[11] = 0;
    data_02111224[12] = 0;
    *(volatile unsigned int*)0x4000240 = 0;
    *(volatile unsigned char*)0x4000244 = 0;
    *(volatile unsigned char*)0x4000245 = 0;
    *(volatile unsigned char*)0x4000246 = 0;
    *(volatile unsigned short*)0x4000248 = 0;
}

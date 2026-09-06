#include <globaldefs.h>

// USA: func_ov017_021999b4
ARM int SetBg2CntFull_021999b4(int screenSize, int colorMode, int screenBase, int charBase) {
    volatile unsigned short* bg2cnt = (volatile unsigned short*)0x400000c;
    int value = (*bg2cnt & 0x43) | (screenSize << 14);
    value |= (colorMode << 7);
    value |= (screenBase << 8);
    value |= (charBase << 2);
    *bg2cnt = value;
    return value;
}

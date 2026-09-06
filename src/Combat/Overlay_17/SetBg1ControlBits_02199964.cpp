#include <globaldefs.h>

// USA: func_ov017_02199964
ARM void SetBg1ControlBits_02199964(int size, int colorMode, int mapBase, int tileBase, int wrap) {
    volatile unsigned short* bg1cnt = (volatile unsigned short*)0x400000a;
    unsigned short v = (*bg1cnt & 0x43) | (size << 14) | (colorMode << 7) | (mapBase << 8) | (tileBase << 2) | (wrap << 13);
    *bg1cnt = v;
}

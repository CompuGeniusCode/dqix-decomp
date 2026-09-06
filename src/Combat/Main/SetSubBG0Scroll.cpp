#include <globaldefs.h>

// USA: func_0204a764
ARM void SetSubBG0Scroll(int h, int v) {
    *(volatile unsigned int*)0x4001010 = (h & 0x1ff) | ((v << 16) & 0x1ff0000);
}

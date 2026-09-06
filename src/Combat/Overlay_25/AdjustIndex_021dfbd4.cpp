#include <globaldefs.h>

// USA: func_ov025_021dfbd4
ARM int AdjustIndex_021dfbd4(int idx) {
    int valid = (idx >= 0 && idx <= 3);
    return valid ? idx + 0xf2 : idx + 0x36;
}

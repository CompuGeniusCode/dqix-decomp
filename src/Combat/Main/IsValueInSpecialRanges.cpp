#include <globaldefs.h>

// USA: func_020a3ee4
ARM int IsValueInSpecialRanges(unsigned int v) {
    if (v >= 0x1f4 && v <= 0x1fc) return 1;
    if (v >= 0x1ff && v <= 0x202) return 1;
    if (v >= 0x258 && v <= 0x294) return 1;
    if (v >= 0x301 && v <= 0x307) return 1;
    return 0;
}

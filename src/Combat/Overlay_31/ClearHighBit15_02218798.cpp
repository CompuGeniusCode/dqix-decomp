#include <globaldefs.h>

// USA: func_ov031_02218798
ARM int ClearHighBit15_02218798(int v) {
    if (v & 0x8000) {
        v &= ~0x8000;
    }
    return v;
}

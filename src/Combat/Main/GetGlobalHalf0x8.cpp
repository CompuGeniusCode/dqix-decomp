#include <globaldefs.h>

extern unsigned short data_02111224[];

// USA: func_020c4b78
ARM unsigned short GetGlobalHalf0x8(void) {
    return data_02111224[4];
}

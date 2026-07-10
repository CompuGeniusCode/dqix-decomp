#include <globaldefs.h>

extern unsigned short data_02111224[];

// USA: func_020c4b48
ARM unsigned short GetGlobalHalf0x4(void) {
    return data_02111224[2];
}

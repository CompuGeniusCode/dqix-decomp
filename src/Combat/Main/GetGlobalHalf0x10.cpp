#include <globaldefs.h>

extern unsigned short data_02111224[];

// USA: func_020c4b68
ARM unsigned short GetGlobalHalf0x10(void) {
    return data_02111224[8];
}

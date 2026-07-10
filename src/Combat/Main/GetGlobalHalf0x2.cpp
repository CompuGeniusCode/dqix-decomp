#include <globaldefs.h>

extern unsigned short data_02111224[];

// USA: func_020c4b38
ARM unsigned short GetGlobalHalf0x2(void) {
    return data_02111224[1];
}

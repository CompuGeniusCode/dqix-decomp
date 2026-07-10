#include <globaldefs.h>

int AccumulateSizeFromFlags020c4bd8(int flags);

extern unsigned short data_02111224[];

// USA: func_020c4c2c
ARM int GetSizeFromFlagsField0x2(void) {
    return AccumulateSizeFromFlags020c4bd8(data_02111224[1]);
}

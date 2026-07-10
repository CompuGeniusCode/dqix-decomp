#include <globaldefs.h>

int AccumulateSizeFromFlags020c4bd8(int flags);

extern unsigned short data_02111224[];

// USA: func_020c4c5c
ARM int GetSizeFromFlagsField0xa(void) {
    return AccumulateSizeFromFlags020c4bd8(data_02111224[5]);
}

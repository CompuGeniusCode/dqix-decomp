#include <globaldefs.h>

extern short data_020e9450[];

// USA: func_02030c9c
ARM short GetTableEntryOdd02030c9c(int x) {
    unsigned short q = (x << 16) / 0x6488;
    return data_020e9450[(q >> 4) * 2 + 1];
}

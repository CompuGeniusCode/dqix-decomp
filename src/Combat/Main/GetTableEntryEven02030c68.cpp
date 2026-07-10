#include <globaldefs.h>

extern short data_020e9450[];

// USA: func_02030c68
ARM short GetTableEntryEven02030c68(int x) {
    unsigned short q = (x << 16) / 0x6488;
    return data_020e9450[(q >> 4) * 2];
}

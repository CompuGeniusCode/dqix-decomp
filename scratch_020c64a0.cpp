#include <globaldefs.h>

int ConsumePendingFlags0x8(void);
extern unsigned short data_020ed668[];
extern unsigned short data_020ed66a[];
extern unsigned short data_020ed66c[];
extern char data_0211125c[];

// USA: func_020c64a0
ARM void ApplyConsumedFlagOffsets020c64a0(void) {
    int idx = ConsumePendingFlags0x8();
    int off = idx * 6;
    unsigned short a = *(unsigned short*)((char*)data_020ed668 + off);
    unsigned short b = *(unsigned short*)((char*)data_020ed66a + off);
    unsigned short c = *(unsigned short*)((char*)data_020ed66c + off);
    *(int*)(data_0211125c + 0x14) = idx;
    *(int*)(data_0211125c + 0x4) = a << 12;
    *(int*)(data_0211125c + 0x18) = b << 12;
    *(int*)(data_0211125c + 0x1c) = c << 12;
}

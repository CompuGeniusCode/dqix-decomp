#include <globaldefs.h>

int ConsumePendingFlags0xa(void);
extern unsigned short data_020ed658[];
extern char data_0211125c[];

// USA: func_020c6688
ARM void StoreVramFlagsAndShift020c6688(void) {
    int consumed = ConsumePendingFlags0xa();
    int idx = consumed >> 4;
    *(int*)(data_0211125c + 0xc) = consumed;
    *(int*)(data_0211125c + 0x8) = data_020ed658[idx] << 0xc;
}

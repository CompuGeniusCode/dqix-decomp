#include <globaldefs.h>

int ConsumePendingFlags0xc(void);

struct Struct0211125c {
    unsigned int flag0;
    unsigned int pad4[3];
    unsigned int field10;
};

extern Struct0211125c data_0211125c;

// USA: func_020c676c  (semantic: HandlePendingFlagsCase_020c676c)
extern "C" ARM void func_020c676c(void) {
    unsigned int v = ConsumePendingFlags0xc();
    data_0211125c.flag0 = v;
    switch (v) {
        case 2:
        case 3:
            data_0211125c.field10 = 0x6800000;
            break;
        case 8:
        case 12:
            data_0211125c.field10 = 0x6840000;
            break;
        case 1:
            data_0211125c.field10 = 0x67e0000;
            break;
        case 4:
            data_0211125c.field10 = 0x6820000;
            break;
        default:
            break;
    }
}

#include <globaldefs.h>

struct SubDispRegs4da0 {
    volatile unsigned int dispcnt;    /* 0x00 */
    unsigned char _pad[4];            /* 0x04 */
    volatile unsigned short bg0cnt;   /* 0x08 */
    volatile unsigned short bg1cnt;   /* 0x0a */
    volatile unsigned short bg2cnt;   /* 0x0c */
    volatile unsigned short bg3cnt;   /* 0x0e */
};

// USA: func_020c4da0  (semantic: GetSubBg2ScreenBaseAddr)
extern "C" ARM unsigned int func_020c4da0(void) {
    struct SubDispRegs4da0* regs = (struct SubDispRegs4da0*)0x4001000;
    int mode = regs->dispcnt & 7;
    unsigned short bg2 = regs->bg2cnt;
    unsigned int sbb = (bg2 & 0x1f00u) >> 8;
    switch (mode) {
        case 0: case 1: case 2: case 3: case 4:
            return 0x6200000 + (sbb << 11);
        case 5:
            return (bg2 & 0x80) ? (0x6200000 + (sbb << 14)) : (0x6200000 + (sbb << 11));
        case 6:
            return 0;
        default:
            return 0;
    }
}

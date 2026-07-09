#include <globaldefs.h>

struct DispRegs4E14 {
    volatile unsigned int dispcnt;    /* 0x00 */
    unsigned char _pad[4];            /* 0x04 */
    volatile unsigned short bg0cnt;   /* 0x08 */
    volatile unsigned short bg1cnt;   /* 0x0a */
    volatile unsigned short bg2cnt;   /* 0x0c */
    volatile unsigned short bg3cnt;   /* 0x0e */
};

// USA: func_020c4e14
ARM unsigned int GetBg3ScreenBaseAddr(void) {
    struct DispRegs4E14* regs = (struct DispRegs4E14*)0x4000000;
    unsigned int mode = regs->dispcnt & 7;
    unsigned short bg3 = regs->bg3cnt;
    unsigned int xbase = ((regs->dispcnt & 0x38000000) >> 27) << 16;
    unsigned int sbb = (bg3 & 0x1f00u) >> 8;
    switch (mode) {
    case 0:
    case 1:
    case 2:
        return 0x6000000 + xbase + (sbb << 11);
    case 3:
    case 4:
    case 5:
        if (bg3 & 0x80) {
            return 0x6000000 + (sbb << 14);
        }
        return 0x6000000 + xbase + (sbb << 11);
    case 6:
        return 0;
    default:
        return 0;
    }
}

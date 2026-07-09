#include <globaldefs.h>

struct DispRegs4FB4 {
    volatile unsigned int dispcnt;    /* 0x00 */
    unsigned char _pad[4];            /* 0x04 */
    volatile unsigned short bg0cnt;   /* 0x08 */
    volatile unsigned short bg1cnt;   /* 0x0a */
    volatile unsigned short bg2cnt;   /* 0x0c */
    volatile unsigned short bg3cnt;   /* 0x0e */
};

// USA: func_020c4fb4
ARM unsigned int GetBg2CharBaseAddr(void) {
    struct DispRegs4FB4* regs = (struct DispRegs4FB4*)0x4000000;
    int mode = regs->dispcnt & 7;
    unsigned short bg2 = regs->bg2cnt;
    if (mode < 5 || (bg2 & 0x80) == 0) {
        unsigned int xbase = ((regs->dispcnt & 0x7000000) >> 24) << 16;
        unsigned int cbb = (bg2 & 0x3cu) >> 2;
        return 0x6000000 + xbase + (cbb << 14);
    }
    return 0;
}

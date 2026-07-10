#include <globaldefs.h>

struct SubDispRegs5004 {
    volatile unsigned int dispcnt;    /* 0x00 */
    unsigned char _pad[4];            /* 0x04 */
    volatile unsigned short bg0cnt;   /* 0x08 */
    volatile unsigned short bg1cnt;   /* 0x0a */
    volatile unsigned short bg2cnt;   /* 0x0c */
    volatile unsigned short bg3cnt;   /* 0x0e */
};

// USA: func_020c5004
ARM unsigned int GetSubBg2CharBaseAddr(void) {
    struct SubDispRegs5004* regs = (struct SubDispRegs5004*)0x4001000;
    int mode = regs->dispcnt & 7;
    unsigned short bg2 = regs->bg2cnt;
    if (mode < 5 || (bg2 & 0x80) == 0) {
        unsigned int cbb = (bg2 & 0x3cu) >> 2;
        return 0x6200000 + (cbb << 14);
    }
    return 0;
}

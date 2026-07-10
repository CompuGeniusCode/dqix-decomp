#include <globaldefs.h>

struct SubDispRegs509C {
    volatile unsigned int dispcnt;    /* 0x00 */
    unsigned char _pad[4];            /* 0x04 */
    volatile unsigned short bg0cnt;   /* 0x08 */
    volatile unsigned short bg1cnt;   /* 0x0a */
    volatile unsigned short bg2cnt;   /* 0x0c */
    volatile unsigned short bg3cnt;   /* 0x0e */
};

// USA: func_020c509c
ARM unsigned int GetSubBg3CharBaseAddr(void) {
    struct SubDispRegs509C* regs = (struct SubDispRegs509C*)0x4001000;
    int mode = regs->dispcnt & 7;
    unsigned short bg3 = regs->bg3cnt;
    if (mode < 3 || (mode < 6 && (bg3 & 0x80) == 0)) {
        unsigned int cbb = (bg3 & 0x3cu) >> 2;
        return 0x6200000 + (cbb << 14);
    }
    return 0;
}

#include <globaldefs.h>

struct DivRegs020c2d18 {
    volatile unsigned short cnt;
    unsigned char pad0[0xe];
    volatile int numer_lo;
    volatile int numer_hi;
    volatile long long denom;
};

// USA: func_020c2d18
ARM int Divide32(int numer, unsigned int denom) {
    struct DivRegs020c2d18* regs = (struct DivRegs020c2d18*)0x4000280;
    regs->cnt = 0;
    regs->numer_lo = numer;
    regs->denom = denom;
    while (regs->cnt & 0x8000) ;
    return *(volatile int*)0x40002a0;
}

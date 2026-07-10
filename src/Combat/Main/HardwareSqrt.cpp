#include <globaldefs.h>

int ReadSqrtResultRounded(void);

struct SqrtRegs020c2c04 {
    volatile unsigned short cnt;
    unsigned char pad0[6];
    volatile int param_lo;
    volatile int param_hi;
};

// USA: func_020c2c04
ARM int HardwareSqrt(int value) {
    struct SqrtRegs020c2c04* regs;
    if (value <= 0) return 0;
    regs = (struct SqrtRegs020c2c04*)0x40002b0;
    regs->cnt = 1;
    regs->param_lo = 0;
    regs->param_hi = value;
    return ReadSqrtResultRounded();
}

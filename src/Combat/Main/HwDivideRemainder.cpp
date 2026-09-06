#include <globaldefs.h>

struct HwDivRegs020c2d54 {
    volatile unsigned short cnt;
    unsigned char pad[0xe];
    volatile unsigned int numer;
    unsigned int pad2;
    volatile long long denom;
};

// USA: func_020c2d54
extern "C" ARM int FastIntModulus(int numer, int denom) {
    struct HwDivRegs020c2d54* div = (struct HwDivRegs020c2d54*)0x4000280;
    div->cnt = 0;
    div->numer = numer;
    div->denom = (unsigned int)denom;
    while (div->cnt & 0x8000) {}
    return *(volatile int*)0x40002a8;
}

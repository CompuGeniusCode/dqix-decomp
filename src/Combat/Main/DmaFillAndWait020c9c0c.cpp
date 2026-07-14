#include <globaldefs.h>

extern "C" void func_01ff8554(unsigned int a, unsigned int b, unsigned int c, unsigned int d);
unsigned int DisableInterrupts(void);
unsigned int RestoreInterrupts(unsigned int mask);

// USA: func_020c9c0c
ARM void DmaFillAndWait020c9c0c(unsigned int channel, unsigned int dst, unsigned int value, unsigned int byteCount) {
    if (byteCount == 0) return;
    volatile unsigned int* dmaCnt = (volatile unsigned int*)(0x040000b0 + (channel * 3 + 2) * 4);
    while (*dmaCnt & 0x80000000) {}
    unsigned int mask = DisableInterrupts();
    *(volatile unsigned int*)(0x040000e0 + channel * 4) = value;
    func_01ff8554(channel, 0x040000e0 + channel * 4, dst, (byteCount >> 2) | 0x85000000);
    RestoreInterrupts(mask);
    while (*dmaCnt & 0x80000000) {}
}

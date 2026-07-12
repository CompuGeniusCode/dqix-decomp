#include <globaldefs.h>

extern "C" void func_020c9fd0(unsigned int a, int b, unsigned int c, unsigned int d);
void ValidateAndFlushRange(unsigned int mode, unsigned int addr, unsigned int size, unsigned int dir);
extern "C" void func_01ff8480(unsigned int a, unsigned int b, unsigned int c, unsigned int d);

// USA: func_020ca8e8
ARM void StartDmaWithFlush020ca8e8(unsigned int chan, unsigned int addr, unsigned int len, unsigned int size) {
    func_020c9fd0(chan, -1, len, size);
    ValidateAndFlushRange(chan, addr, size, 0x1000000);
    if (size == 0) return;
    volatile unsigned int* dmaCnt = (volatile unsigned int*)(0x040000b0 + (chan * 3 + 2) * 4);
    while (*dmaCnt & 0x80000000) {}
    func_01ff8480(chan, addr, len, 0xaf000001);
}

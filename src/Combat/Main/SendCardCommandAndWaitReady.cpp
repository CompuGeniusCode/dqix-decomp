#include <globaldefs.h>

void WriteCardCommand(unsigned int a, unsigned int b);

extern void* data_020f22cc;

// USA: func_020d0cd8
ARM unsigned int SendCardCommandAndWaitReady(int unused) {
    unsigned int v;
    WriteCardCommand(0xb8000000, 0);
    v = *(unsigned int*)((char*)data_020f22cc + 0x60);
    v = (v & ~0x7000000) | 0xa7000000;
    v &= 0xffffe000;
    *(volatile unsigned int*)0x40001a4 = v;
    while ((*(volatile unsigned int*)0x40001a4 & 0x800000) == 0)
        ;
    return *(volatile unsigned int*)0x4100010;
}

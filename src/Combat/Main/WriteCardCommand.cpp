#include <globaldefs.h>

// USA: func_020d08d8
ARM void WriteCardCommand(unsigned int a, unsigned int b) {
    volatile unsigned char *p;
    while (*(volatile unsigned int*)0x40001a4 & 0x80000000)
        ;
    p = (volatile unsigned char*)0x40001a1;
    p[0] = 0xc0;
    p[7] = a >> 24;
    p[8] = a >> 16;
    p[9] = a >> 8;
    p[10] = a;
    p[11] = b >> 24;
    p[12] = b >> 16;
    p[13] = b >> 8;
    p[14] = b;
}

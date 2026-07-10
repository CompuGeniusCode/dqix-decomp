#include <globaldefs.h>

extern char data_0210a010;

// USA: func_020b3924
ARM void PackFieldsAt0x9c(unsigned int a, unsigned int b, unsigned int c, unsigned int d, unsigned int e, unsigned int f) {
    *(unsigned int*)(&data_0210a010 + 0x9c) = a | (b << 4) | (c << 6) | f | (d << 24) | (e << 16);
}

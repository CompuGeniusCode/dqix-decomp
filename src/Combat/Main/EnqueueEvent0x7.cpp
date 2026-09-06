#include <globaldefs.h>

int EnqueueEvent0x07(int, int, int, int, int);

// USA: func_020d1ea0
ARM int EnqueueEvent0x7(int a, int b, int c) {
    return EnqueueEvent0x07(a, b, 0xc, c, 2);
}

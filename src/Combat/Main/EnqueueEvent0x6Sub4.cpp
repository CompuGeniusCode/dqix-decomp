#include <globaldefs.h>

int EnqueueEvent0x06(int, int, int, int);

// USA: func_020d1e88
ARM int EnqueueEvent0x6Sub4(int a, int b) {
    return EnqueueEvent0x06(a, 4, b, 1);
}

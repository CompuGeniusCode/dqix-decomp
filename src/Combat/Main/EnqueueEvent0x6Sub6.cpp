#include <globaldefs.h>

int EnqueueEvent0x06(int, int, int, int);

// USA: func_020d1e70
ARM int EnqueueEvent0x6Sub6(int a, int b) {
    return EnqueueEvent0x06(a, 6, b, 2);
}

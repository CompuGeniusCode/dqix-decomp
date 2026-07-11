#include <globaldefs.h>

// USA: func_020ca7e0
ARM int AtomicSwap(int value, int* addr) {
    asm {
        swp value, value, [addr]
    }
    return value;
}

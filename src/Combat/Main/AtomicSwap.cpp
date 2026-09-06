#include <globaldefs.h>

// USA: _Z10AtomicSwapiPi
ARM int AtomicSwap(int value, int* addr) {
    asm {
        swp value, value, [addr]
    }
    return value;
}

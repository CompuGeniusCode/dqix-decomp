#include <globaldefs.h>

// USA: func_020c8534
ARM int GetSharedWordDa0(int index) {
    return ((volatile int*)0x27ffda0)[index];
}

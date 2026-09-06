#include <globaldefs.h>

// USA: func_020c86e8
ARM void SetSharedWordDa0(int index, int value) {
    ((volatile int*)0x27ffda0)[index] = value;
}

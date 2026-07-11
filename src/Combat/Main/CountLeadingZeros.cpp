#include <globaldefs.h>

// USA: func_020c9a4c
ARM unsigned int CountLeadingZeros(unsigned int value) {
    asm {
        clz value, value
    }
    return value;
}

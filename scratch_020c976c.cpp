#include <globaldefs.h>

// USA: func_020c976c
ARM unsigned int ReduceMod4_020c976c(unsigned int a) {
    for (;;) {
        unsigned int b = a - 4;
        if (b > a) return b;
        a = b;
    }
}

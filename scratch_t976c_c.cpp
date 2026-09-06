#include <globaldefs.h>

// USA: func_020c976c
ARM unsigned int Func020c976c(unsigned int a) {
Loop:
    unsigned int old = a;
    a -= 4;
    if (old >= 4) goto Loop;
    return a;
}

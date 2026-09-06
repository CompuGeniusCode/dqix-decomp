#include <globaldefs.h>

// USA: func_020c976c
ARM unsigned int Func020c976c(unsigned int a) {
Loop:
    a -= 4;
    if (a + 4 >= 4) goto Loop;
    return a;
}

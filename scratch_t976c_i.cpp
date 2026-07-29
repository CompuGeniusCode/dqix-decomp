#include <globaldefs.h>

// USA: func_020c976c
ARM unsigned int Func020c976c(unsigned int a) {
    return (a >= 4) ? Func020c976c(a - 4) : (a - 4);
}

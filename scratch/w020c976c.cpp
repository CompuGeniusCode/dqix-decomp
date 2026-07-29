#include <globaldefs.h>

// USA: func_020c976c
ARM void WaitByLoop(unsigned int n) {
    unsigned int old;
    do {
        old = n;
        n -= 4;
    } while (old >= 4);
}

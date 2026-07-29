#include <globaldefs.h>

// USA: func_0200ee38
ARM void CallDecrementing_0200ee38(unsigned int lo, unsigned int hi, unsigned int step, void (*func)(unsigned int)) {
    if (hi <= lo) return;
    unsigned int cur = hi;
    do {
        cur -= step;
        func(cur);
    } while (cur > lo);
}

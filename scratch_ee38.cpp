#include <globaldefs.h>

// USA: func_0200ee38
ARM void func_0200ee38(unsigned int p1, unsigned int p2, unsigned int p3, void (*cb)(unsigned int)) {
    if (p2 <= p1) return;
    unsigned int i = p2;
    do {
        i -= p3;
        cb(i);
    } while (i > p1);
}

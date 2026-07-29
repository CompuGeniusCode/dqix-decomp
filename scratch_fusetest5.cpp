#include <globaldefs.h>

ARM int fusetest5(int a, unsigned int b) {
    int c = a - (int)(b >> 5);
    if (0 >= c) return 1;
    return c;
}

#include <globaldefs.h>

ARM int fusetest4(int a, unsigned int b) {
    int c = a - (int)(b >> 5);
    if (c < 1) return 1;
    return c;
}

#include <globaldefs.h>

ARM int fusetest2(int a, unsigned int b) {
    int c = a - (int)(b >> 5);
    if (c == 0) return 1;
    return c;
}

#include <globaldefs.h>

ARM int fusetest3(int a, unsigned int b, int d) {
    int c = d - (int)(b >> 5);
    if (c <= 0) return 1;
    return c;
}

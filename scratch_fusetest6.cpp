#include <globaldefs.h>

ARM int fusetest6(int a, int b) {
    int c = a - b;
    if (c <= 0) return 1;
    return c;
}

#include <globaldefs.h>

ARM int fusetest7(int a, int b) {
    int c;
    if ((c = a - b) <= 0) return 1;
    return c;
}

#include <globaldefs.h>

ARM unsigned int TestDouble(unsigned int a, unsigned int s) {
    unsigned int x = a << s;
    x = x + x;
    return x;
}

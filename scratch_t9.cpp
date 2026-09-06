#include <globaldefs.h>
extern "C" ARM int test9(unsigned int i) {
    unsigned char b = i;
    return b << 3;
}

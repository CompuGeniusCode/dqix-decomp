#include <globaldefs.h>
extern "C" ARM int test8(unsigned int i) {
    unsigned int m = i & 0xff;
    return m << 3;
}

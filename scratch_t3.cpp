#include <globaldefs.h>
extern "C" ARM int test3(int i) {
    unsigned char b = (unsigned char)i;
    return b * 8;
}

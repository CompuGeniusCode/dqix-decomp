#include <globaldefs.h>
extern "C" ARM int test10(unsigned int i) {
    return (i * 8) & 0x7f8;
}

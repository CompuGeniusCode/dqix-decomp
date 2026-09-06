#include <globaldefs.h>
extern "C" ARM int test6(unsigned int i) {
    return (i & 0xff) * 8;
}

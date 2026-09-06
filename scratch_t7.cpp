#include <globaldefs.h>
extern "C" ARM int test7(unsigned int i) {
    return (i & 0xff) << 3;
}

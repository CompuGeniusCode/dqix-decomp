#include <globaldefs.h>
extern "C" ARM int test11(unsigned int i) {
    return (i % 256) * 8;
}

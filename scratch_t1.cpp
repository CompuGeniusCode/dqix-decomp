#include <globaldefs.h>
extern "C" ARM int test1(int i) {
    return (i & 0xff) * 8;
}

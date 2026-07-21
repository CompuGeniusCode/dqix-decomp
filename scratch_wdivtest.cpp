#include <globaldefs.h>

extern "C" ARM int divtest(unsigned short v) {
    return (int)(v * 0x37) / 100;
}

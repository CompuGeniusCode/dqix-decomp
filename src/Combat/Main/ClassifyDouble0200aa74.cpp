#include <globaldefs.h>

#pragma optimize_for_size off

// USA: func_0200aa74  (semantic: ClassifyDouble0200aa74)
extern "C" ARM int func_0200aa74(double x) {
    unsigned int hi = ((unsigned int*)&x)[1];
    unsigned int exp = hi & 0x7ff00000;
    if (exp == 0) goto zerocase;
    if (exp != 0x7ff00000) goto normalcase;
    if ((hi & 0xfffff) != 0 || ((unsigned int*)&x)[0] != 0) {
        return 1;
    }
    return 2;
zerocase:
    if ((hi & 0xfffff) != 0 || ((unsigned int*)&x)[0] != 0) {
        return 5;
    }
    return 3;
normalcase:
    return 4;
}

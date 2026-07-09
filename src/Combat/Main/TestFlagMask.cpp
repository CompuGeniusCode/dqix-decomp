#include <globaldefs.h>

// USA: func_02012430
ARM int TestFlagMask(unsigned short* obj, int mask) {
    return (*obj & mask) != 0;
}

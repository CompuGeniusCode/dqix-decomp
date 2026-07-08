#include <globaldefs.h>

// USA: func_0203b520
ARM void ClearBitsInField8(unsigned int* obj, unsigned int mask) {
    obj[2] &= ~mask;
}

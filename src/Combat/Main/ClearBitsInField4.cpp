#include <globaldefs.h>

// USA: func_0203b4e8
ARM void ClearBitsInField4(unsigned int* obj, unsigned int mask) {
    obj[1] &= ~mask;
}

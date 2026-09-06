#include <globaldefs.h>

// USA: func_0203b4b0
ARM void ClearBitsInWord(unsigned int* obj, unsigned int mask) {
    *obj &= ~mask;
}

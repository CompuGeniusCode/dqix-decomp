#include <globaldefs.h>

// USA: func_02027bbc
ARM void ClearFlags0xa97(unsigned char* base, int mask) {
    base[0xa97] &= ~mask;
}

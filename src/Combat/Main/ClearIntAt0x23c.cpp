#include <globaldefs.h>

// USA: func_020a27b8
ARM void ClearIntAt0x23c(unsigned char* obj) {
    *(unsigned int*)(obj + 0x23c) = 0;
}

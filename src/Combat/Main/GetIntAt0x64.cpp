#include <globaldefs.h>

// USA: func_020377cc
ARM int GetIntAt0x64(unsigned char* obj) {
    return *(int*)(obj + 0x64);
}

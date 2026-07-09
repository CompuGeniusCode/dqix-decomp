#include <globaldefs.h>

// USA: func_020b2e50
ARM unsigned int GetScaledHalfword0x1c(unsigned char* obj) {
    return obj ? (*(unsigned short*)(obj + 0x1c) << 3) : 0;
}

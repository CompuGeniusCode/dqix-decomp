#include <globaldefs.h>

// USA: func_020b2f30
ARM unsigned int GetScaledHalfword0x30(unsigned char* obj) {
    return obj ? (*(unsigned short*)(obj + 0x30) << 3) : 0;
}

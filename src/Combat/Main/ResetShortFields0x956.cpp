#include <globaldefs.h>

// USA: func_020863a0
ARM void ResetShortFields0x956(unsigned char* obj) {
    *(short*)(obj + 0x956) = 0;
    *(short*)(obj + 0x958) = -1;
    *(short*)(obj + 0x95a) = 0;
    *(short*)(obj + 0x95c) = 0;
    *(short*)(obj + 0x95e) = -1;
}

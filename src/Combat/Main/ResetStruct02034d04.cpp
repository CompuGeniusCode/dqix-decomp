#include <globaldefs.h>

// USA: func_02034d04
ARM void ResetStruct02034d04(unsigned char* obj) {
    *(int*)(obj + 0) = 0;
    *(int*)(obj + 4) = 0;
    *(unsigned short*)(obj + 8) = 0;
    *(unsigned short*)(obj + 0xa) = 0;
    *(int*)(obj + 0xc) = 0;
}

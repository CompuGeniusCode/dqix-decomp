#include <globaldefs.h>

// USA: func_0201250c
ARM void InvalidateBattlerField0x18(unsigned char* obj) {
    *(int*)(obj + 0x18) = -1;
}

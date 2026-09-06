#include <globaldefs.h>

// USA: func_020546b4
ARM void SetField0x2d1(void* obj, unsigned char value) {
    *(unsigned char*)((char*)obj + 0x2d1) = value;
}

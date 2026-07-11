#include <globaldefs.h>

// USA: func_02012034
ARM unsigned char GetByte0x7f70(void* obj) {
    return ((unsigned char*)obj + 0x7000)[0xf70];
}

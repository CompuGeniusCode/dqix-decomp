#include <globaldefs.h>

// USA: func_02053eb4
ARM unsigned char GetByteFieldAt0x1a0(void* obj, int extra) {
    return *((unsigned char*)obj + extra + 0x1a0);
}

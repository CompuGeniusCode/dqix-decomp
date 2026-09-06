#include <globaldefs.h>

// USA: func_02011518
ARM int GetCheckedSignedByte(void* obj, unsigned int idx) {
    if (idx < ((unsigned char*)obj)[0x5721]) {
        return ((signed char*)obj + idx)[0x571d];
    }
    return -1;
}

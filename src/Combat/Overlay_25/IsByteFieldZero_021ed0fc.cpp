#include <globaldefs.h>

// USA: func_ov025_021ed0fc
ARM int IsByteFieldZero_021ed0fc(void* obj) {
    return *(unsigned char*)((char*)obj + 0x300) == 0;
}

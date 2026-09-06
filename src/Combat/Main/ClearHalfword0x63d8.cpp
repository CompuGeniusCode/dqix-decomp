#include <globaldefs.h>

// USA: func_02011600
ARM void ClearHalfword0x63d8(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(unsigned short*)(base + 0x63d8) = 0;
}

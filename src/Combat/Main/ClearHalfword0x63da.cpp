#include <globaldefs.h>

// USA: func_02011634
ARM void ClearHalfword0x63da(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    *(unsigned short*)(base + 0x63da) = 0;
}

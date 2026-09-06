#include <globaldefs.h>

// USA: func_02011628
ARM unsigned short GetHalfword0x63da(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    return *(unsigned short*)(base + 0x63da);
}

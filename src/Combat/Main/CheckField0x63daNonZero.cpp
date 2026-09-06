#include <globaldefs.h>

// USA: func_02011610
ARM int CheckField0x63daNonZero(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    return *(unsigned short*)(base + 0x63da) != 0;
}

#include <globaldefs.h>

// USA: func_02011644
ARM int GetWord0x63e0(void* obj) {
    unsigned char* base = (unsigned char*)obj;
    return *(int*)(base + 0x63e0);
}

#include <globaldefs.h>

// USA: func_02017d7c
ARM void ClearFlagBytes02017d7c(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    *(unsigned char*)(p + 0x281d) = 0;
    *(unsigned char*)(p + 0x281e) = 0;
}

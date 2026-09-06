#include <globaldefs.h>

// USA: func_02017d68
ARM void SetFlagBytes02017d68(void* obj) {
    unsigned char* p = (unsigned char*)obj;
    *(unsigned char*)(p + 0x281d) = 1;
    *(unsigned char*)(p + 0x281e) = 1;
}

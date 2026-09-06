#include <globaldefs.h>

void ReleaseHandleField340(void*);

// USA: func_020939fc
ARM void ClearFlag0x3c9Bit0AndCleanup(unsigned char* obj) {
    obj[0x3c9] &= ~1;
    ReleaseHandleField340(obj);
}

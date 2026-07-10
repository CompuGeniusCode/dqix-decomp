#include <globaldefs.h>

unsigned int ClearAndInit020d84f8(void* obj, unsigned int len);

// USA: func_020d8a48
ARM void ClearAndResetState020d8a48(void* obj) {
    ClearAndInit020d84f8(obj, 0x4c);
    *(unsigned short*)obj = 0;
    *((unsigned short*)obj + 1) = 0;
}

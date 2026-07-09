#include <globaldefs.h>

// USA: func_02054224
ARM void SetFlags0x180At0x18c(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + 0x18c);
    *flags |= 0x180;
}

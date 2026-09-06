#include <globaldefs.h>

// USA: func_02054234
ARM void ClearFlag0x80SetFlag0x100(void* obj) {
    unsigned int* flags = (unsigned int*)((char*)obj + 0x18c);
    *flags = (*flags & ~0x80) | 0x100;
}

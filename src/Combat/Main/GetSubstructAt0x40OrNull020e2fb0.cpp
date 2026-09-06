#include <globaldefs.h>

// USA: func_020e2fb0
ARM void* GetSubstructAt0x40OrNull020e2fb0(void* base) {
    return base ? (char*)base + 0x40 : NULL;
}

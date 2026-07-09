#include <globaldefs.h>

// USA: func_020b2e64
ARM void SetNonNullFields0x8And0x18(unsigned char* obj, void* a, void* b) {
    if (a) *(void**)(obj + 0x8) = a;
    if (b) *(void**)(obj + 0x18) = b;
}

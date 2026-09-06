#include <globaldefs.h>

// USA: func_ov025_021e8a64
ARM void* GetArrayEntry_021e8a64_021e8a64(char* obj) {
    unsigned char idx = *(unsigned char*)(obj + 0x30);
    return *(void**)(obj + 0x20 + idx * 4);
}

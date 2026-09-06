#include <globaldefs.h>

// USA: func_ov025_021e8a54
ARM void* GetArrayEntry_021e8a54_021e8a54(char* obj) {
    unsigned char idx = *(unsigned char*)(obj + 0x30);
    return *(void**)(obj + 0x10 + idx * 4);
}

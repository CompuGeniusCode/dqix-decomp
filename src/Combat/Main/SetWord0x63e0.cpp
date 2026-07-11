#include <globaldefs.h>

// USA: func_02011650
ARM void SetWord0x63e0(void* obj, int value) {
    unsigned char* base = (unsigned char*)obj;
    *(int*)(base + 0x63e0) = value;
}

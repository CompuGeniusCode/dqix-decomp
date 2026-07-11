#include <globaldefs.h>

// USA: func_0205b228
ARM void SetFieldsAt0x4And0x8_0205b228(void* obj, int value, unsigned char flag) {
    *(int*)((char*)obj + 0x4) = value;
    *(unsigned char*)((char*)obj + 0x8) = flag;
}

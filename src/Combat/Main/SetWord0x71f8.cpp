#include <globaldefs.h>

// USA: func_0201206c
ARM void SetWord0x71f8(void* obj, int value) {
    *(int*)((unsigned char*)obj + 0x7000 + 0x1f8) = value;
}

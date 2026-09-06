#include <globaldefs.h>

// USA: func_ov002_021556ec
ARM void SetBytes485And486_021556ec(void* obj, int a, int b) {
    unsigned char* p = (unsigned char*)obj + 0x2000;
    p[0x485] = (unsigned char)a;
    p[0x486] = (unsigned char)b;
}

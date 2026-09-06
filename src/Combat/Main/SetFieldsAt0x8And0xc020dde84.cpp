#include <globaldefs.h>

// USA: func_020dde84
ARM void SetFieldsAt0x8And0xc020dde84(char* obj, int a, int b) {
    *(int*)(obj + 0x8) = a;
    *(int*)(obj + 0xc) = b;
}

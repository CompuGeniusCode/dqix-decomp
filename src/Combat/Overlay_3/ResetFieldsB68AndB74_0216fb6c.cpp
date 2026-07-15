// USA: func_ov003_0216fb6c
#include <globaldefs.h>

ARM void ResetFieldsB68AndB74_0216fb6c(char* obj) {
    int i;
    for (i = 0; i < 3; i++) {
        *(int*)(obj + i * 4 + 0x1000 + 0xb68) = -1;
    }
    *(int*)(obj + 0x1000 + 0xb74) = 0;
}

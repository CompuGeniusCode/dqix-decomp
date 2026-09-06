#include <globaldefs.h>

// USA: func_0200fb40
ARM void ClearSubstructBytes(void* obj) {
    char* base = (char*)obj;
    unsigned char i;
    base[0x7f74] = 0;
    base[0x7f75] = 0;
    for (i = 0; i < 4; i++) {
        (base + i)[0x7f76] = 0;
    }
    base[0x7f7a] = 0;
}

#include <globaldefs.h>

extern unsigned char data_020fdcce;

// USA: func_02026348
ARM void StoreByteList02026348(char* obj, unsigned char* src, int count) {
    int i;
    if ((unsigned int)count > 4) {
        obj[0x75c] = 0;
        return;
    }
    for (i = 0; i < count; i++) {
        char* p = obj + i;
        unsigned char b = src[i];
        p[0x758] = b;
        (&data_020fdcce)[b << 5] = 1;
    }
    obj[0x75c] = count;
}

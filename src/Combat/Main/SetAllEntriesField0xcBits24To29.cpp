#include <globaldefs.h>

ARM void SetField0xcBits24To29(void* obj, unsigned int index, unsigned int value);

// USA: func_020b72ec
ARM void SetAllEntriesField0xcBits24To29(void* obj, unsigned int value) {
    unsigned int i = 0;
    if (i < *(unsigned char*)((char*)obj + 0x18)) {
        do {
            SetField0xcBits24To29(obj, i, value);
            i++;
        } while (i < *(unsigned char*)((char*)obj + 0x18));
    }
}

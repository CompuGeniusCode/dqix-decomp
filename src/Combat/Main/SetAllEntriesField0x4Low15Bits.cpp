#include <globaldefs.h>

ARM void SetField0x4Low15Bits(void* obj, unsigned int index, unsigned int value);

// USA: func_020b726c
ARM void SetAllEntriesField0x4Low15Bits(void* obj, unsigned int value) {
    unsigned int i = 0;
    if (i < *(unsigned char*)((char*)obj + 0x18)) {
        do {
            SetField0x4Low15Bits(obj, i, value);
            i++;
        } while (i < *(unsigned char*)((char*)obj + 0x18));
    }
}

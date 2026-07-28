#include <globaldefs.h>

void SetField0xcBits16To20(void* obj, unsigned int index, unsigned int value);

// USA: func_020b732c  (semantic: SetAllFieldBitsB_020b732c)
extern "C" ARM void func_020b732c(void* obj, unsigned int value) {
    unsigned int i = 0;
    if (*(unsigned char*)((char*)obj + 0x18) <= i) {
        return;
    }
    do {
        SetField0xcBits16To20(obj, i, value);
        i++;
    } while (i < *(unsigned char*)((char*)obj + 0x18));
}

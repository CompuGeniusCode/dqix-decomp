#include <globaldefs.h>

void SetField0x4Bits16To30(void* obj, unsigned int index, unsigned int value);

// USA: func_020b72ac  (semantic: SetAllFieldBitsA_020b72ac)
extern "C" ARM void func_020b72ac(void* obj, unsigned int value) {
    unsigned int i = 0;
    if (*(unsigned char*)((char*)obj + 0x18) <= i) {
        return;
    }
    do {
        SetField0x4Bits16To30(obj, i, value);
        i++;
    } while (i < *(unsigned char*)((char*)obj + 0x18));
}

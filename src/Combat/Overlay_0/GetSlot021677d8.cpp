#include <globaldefs.h>

// USA: func_ov000_021677d8
ARM void* GetSlot021677d8(void* work, int idx) {
    if (idx >= 0) {
        if (idx < 4) {
            return (char*)work + 0x5910 + idx * 0x10;
        }
    }
    return (void*)0;
}

#include <globaldefs.h>

// USA: func_020120a0
ARM void* GetField0x74deForValidIndex(char* base, unsigned int index) {
    if (index < 4) {
        return base + 0x74de + index * 8;
    }
    return NULL;
}

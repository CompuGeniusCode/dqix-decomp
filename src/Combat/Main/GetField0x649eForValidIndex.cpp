#include <globaldefs.h>

// USA: func_02011aa0
ARM void* GetField0x649eForValidIndex(char* base, unsigned int index) {
    void* result = NULL;
    if (index <= 3) {
        result = base + 0x649e;
    }
    return result;
}

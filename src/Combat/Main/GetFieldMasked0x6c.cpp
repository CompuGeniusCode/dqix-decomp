#include <globaldefs.h>

// USA: func_02037a88
ARM int GetFieldMasked0x6c(void* obj, int mask) {
    return *(int*)((char*)obj + 0x6c) & mask;
}

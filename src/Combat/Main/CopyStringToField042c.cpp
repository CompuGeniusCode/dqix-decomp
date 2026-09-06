#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

// USA: func_0204653c
ARM void CopyStringToField042c(void* obj, char* src) {
    CopyStringBounded(src, (char*)obj + 0x42c, 0x40);
}

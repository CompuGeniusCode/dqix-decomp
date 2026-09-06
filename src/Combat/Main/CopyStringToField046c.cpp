#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

// USA: func_02046558
ARM void CopyStringToField046c(void* obj, char* src) {
    CopyStringBounded(src, (char*)obj + 0x46c, 0x40);
}

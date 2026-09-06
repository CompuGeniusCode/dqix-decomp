#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

// USA: func_02046504
ARM void CopyStringToField0x3ac(char* base, char* src) {
    CopyStringBounded(src, base + 0x3ac, 0x40);
}

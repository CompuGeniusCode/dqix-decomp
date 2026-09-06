#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

// USA: func_02046520
ARM void CopyStringToField0x3ec(char* base, char* src) {
    CopyStringBounded(src, base + 0x3ec, 0x40);
}

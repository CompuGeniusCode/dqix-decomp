#include <globaldefs.h>

void CopyStringBounded(char* src, char* dst, int size);

// USA: func_020464e8
ARM void CopyStringToIndexedField0x2ec(char* base, int index, char* src) {
    CopyStringBounded(src, base + 0x2ec + index * 0x40, 0x40);
}

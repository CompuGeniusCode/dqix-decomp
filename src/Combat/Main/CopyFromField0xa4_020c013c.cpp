#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020c013c
ARM int CopyFromField0xa4_020c013c(char* obj, void* dst, int length, int offset) {
    VectorizedInvertedMemcpy(*(char**)(obj + 0xa4) + offset, dst, length);
    return length;
}

#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020cbc34
ARM int WriteRegionToOffset020cbc34(char* obj, void* src, int offset, unsigned int length) {
    VectorizedInvertedMemcpy(src, *(char**)(obj + 0x28) + offset, length);
    return 0;
}

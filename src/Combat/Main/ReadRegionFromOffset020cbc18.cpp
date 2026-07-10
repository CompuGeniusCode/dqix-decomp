#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020cbc18
ARM int ReadRegionFromOffset020cbc18(char* obj, void* dst, int offset, unsigned int length) {
    VectorizedInvertedMemcpy(*(char**)(obj + 0x28) + offset, dst, length);
    return 0;
}

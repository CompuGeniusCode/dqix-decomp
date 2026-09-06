#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020119f8
ARM unsigned char CopyToRegion0x6482IfDst(char* obj, void* dst) {
    if (dst != NULL) {
        VectorizedInvertedMemcpy(obj + 0x6482, dst, 0x1c);
    }
    return *(unsigned char*)(obj + 0x6480);
}

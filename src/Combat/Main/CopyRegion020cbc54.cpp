#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020cbc54
ARM int CopyRegion020cbc54(void* obj, void* dst, void* src, unsigned int length) {
    VectorizedInvertedMemcpy(src, dst, length);
    return 0;
}

#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02011a24
ARM void CopyInToRegion0x6482(char* obj, void* src) {
    VectorizedInvertedMemcpy(src, obj + 0x6482, 0x1c);
}

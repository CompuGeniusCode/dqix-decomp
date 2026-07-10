#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020a40e8
ARM void ClearStruct020a40e8(void* obj) {
    VectorizedMemset(obj, 0, 0x1c4);
}

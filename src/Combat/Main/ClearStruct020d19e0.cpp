#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_020d19e0
ARM void ClearStruct020d19e0(void* obj) {
    VectorizedMemset(obj, 0, 0x24);
}

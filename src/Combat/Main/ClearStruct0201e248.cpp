#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_0201e248
ARM void ClearStruct0201e248(void* obj) {
    VectorizedMemset(obj, 0, 0x88);
}

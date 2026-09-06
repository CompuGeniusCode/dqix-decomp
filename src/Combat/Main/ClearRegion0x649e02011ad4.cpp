#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02011ad4
ARM void ClearRegion0x649e02011ad4(char* obj) {
    VectorizedMemset(obj + 0x649e, 0, 0x40);
}

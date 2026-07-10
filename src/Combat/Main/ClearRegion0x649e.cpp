#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_02011ab8
ARM void ClearRegion0x649e(char* obj) {
    VectorizedMemset(obj + 0x649e, 0, 0x40);
}

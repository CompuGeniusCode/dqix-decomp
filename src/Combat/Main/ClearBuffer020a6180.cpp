#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020a6180
ARM void ClearBuffer020a6180(void* obj) {
    memset(obj, 0, 0x200);
}

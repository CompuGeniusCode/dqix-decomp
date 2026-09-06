#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020865ec
ARM void ClearRegion020865ec(char* obj) {
    memset(obj, 0, 0x14);
    *(char*)(obj + 0x10) = -1;
}

#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020de824
ARM void* ZeroInitReturn020de824(void* obj) {
    memset(obj, 0, 0x14);
    *((unsigned char*)obj + 0x14) = 0;
    return obj;
}

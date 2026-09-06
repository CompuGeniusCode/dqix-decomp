#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011a74
ARM void CopyStringToField0x649e(char* obj, unsigned int idx, const char* src) {
    char* dst;
    if (src == NULL) return;
    dst = obj + 0x649e;
    if (dst == NULL) return;
    if (idx > 3) return;
    strcpy(dst, src);
}

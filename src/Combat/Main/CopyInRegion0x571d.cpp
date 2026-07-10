#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020114c0
ARM void CopyInRegion0x571d(char* obj, int len, void* src) {
    memcpy(obj + 0x571d, src, len);
    *(unsigned char*)(obj + 0x5721) = (unsigned char)len;
}

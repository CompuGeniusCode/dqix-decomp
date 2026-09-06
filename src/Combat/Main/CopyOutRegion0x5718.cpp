#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02011494
ARM unsigned char CopyOutRegion0x5718(char* obj, void* dst) {
    unsigned char len = *(unsigned char*)(obj + 0x571c);
    memcpy(dst, obj + 0x5718, len);
    return *(unsigned char*)(obj + 0x571c);
}

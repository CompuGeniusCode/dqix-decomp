#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020114ec
ARM unsigned char CopyOutRegion0x571d(char* obj, void* dst) {
    unsigned char len = *(unsigned char*)(obj + 0x5721);
    memcpy(dst, obj + 0x571d, len);
    return *(unsigned char*)(obj + 0x5721);
}

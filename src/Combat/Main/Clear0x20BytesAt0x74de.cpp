#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02012084
ARM void* Clear0x20BytesAt0x74de(unsigned char* obj) {
    return memset(obj + 0x74de, 0, 0x20);
}

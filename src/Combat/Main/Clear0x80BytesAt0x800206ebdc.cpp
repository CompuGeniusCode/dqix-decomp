#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206ebdc
ARM void* Clear0x80BytesAt0x800206ebdc(unsigned char* obj) {
    return memset(obj + 0x80, 0, 0x80);
}

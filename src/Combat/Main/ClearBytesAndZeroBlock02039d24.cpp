#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02039d24
ARM void ClearBytesAndZeroBlock02039d24(unsigned char* obj) {
    obj[0x1cb] = 0;
    obj[0x1cc] = 0;
    obj[0x1cd] = 0;
    memset(obj + 0x1d0, 0, 0x80);
}

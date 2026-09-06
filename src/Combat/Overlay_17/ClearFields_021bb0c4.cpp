#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov017_021bb0c4
ARM void ClearFields_021bb0c4(unsigned char* obj) {
    obj[0xfc] = 0;
    *(unsigned short*)(obj + 0x11a) = 0;
    memset(obj + 0x13c, 0, 0x12);
    memset(obj + 0x150, 0, 0xa);
    *(int*)(obj + 0x15c) = 0;
    obj[0xfe] = 0;
}

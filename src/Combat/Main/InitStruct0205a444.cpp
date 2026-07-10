#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0205a444
ARM void InitStruct0205a444(char* obj) {
    memset(obj, 0, 0x24);
    memset(obj + 0x24, 0, 0x14);
    *(int*)(obj + 0x38) = 0;
    *(int*)(obj + 0x40) = 0;
    *(int*)(obj + 0x44) = 0;
    *(int*)(obj + 0x48) = 0;
    *(short*)(obj + 0x4c) = 0;
    *(short*)(obj + 0x4e) = 0;
    *(int*)(obj + 0x3c) = 0;
    *(char*)(obj + 0x50) = 1;
}

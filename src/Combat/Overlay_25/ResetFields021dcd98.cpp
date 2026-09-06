#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov025_021dcd98
ARM void ResetFields021dcd98(char* obj) {
    obj[0x6f00] = 0;
    obj[0x6eff] = 0;
    memset(obj + 0x6fba, -1, 8);
    *(short*)(obj + 0x6fc2) = 0;
    *(int*)(obj + 0x6fc4) = 0;
    *(int*)(obj + 0x6fc8) = 0;
    *(int*)(obj + 0x6fcc) = 0;
    *(int*)(obj + 0x6fd0) = 0;
}

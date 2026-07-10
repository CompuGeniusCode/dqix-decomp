#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0207b9cc
ARM void ClearRegions0207b9cc(char* obj) {
    *(int*)(obj + 0x304) = 0;
    *(int*)(obj + 0x308) = 0;
    memset(obj, 0, 0xe8);
    memset(obj, 0, 0x17c);
    memset(obj + 0x17c, 0, 0x188);
}

#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02093980
ARM void ClearRegion02093980(char* obj) {
    memset(obj, 0, 0x30);
    *(short*)(obj + 0x30) = -1;
    *(char*)(obj + 0x32) = -1;
    *(char*)(obj + 0x33) = 0;
}

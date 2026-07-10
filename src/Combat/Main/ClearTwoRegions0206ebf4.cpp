#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206ebf4
ARM void ClearTwoRegions0206ebf4(char* obj) {
    memset(obj, 0, 0x80);
    memset(obj + 0x80, 0, 0x80);
}

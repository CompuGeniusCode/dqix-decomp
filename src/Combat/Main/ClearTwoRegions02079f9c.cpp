#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02079f9c
ARM void ClearTwoRegions02079f9c(char* obj) {
    memset(obj + 0xc, 0, 0xc);
    memset(obj + 0x24, 0, 0xc);
}

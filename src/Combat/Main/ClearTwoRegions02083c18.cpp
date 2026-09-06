#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02083c18
ARM void ClearTwoRegions02083c18(char* obj) {
    memset(obj + 0x8ec, 0, 0x24);
    memset(obj + 0x910, 0, 9);
}

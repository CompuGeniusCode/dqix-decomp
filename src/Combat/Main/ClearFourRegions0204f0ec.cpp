#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0204f0ec
ARM void ClearFourRegions0204f0ec(char* obj) {
    memset(obj + 0xc, 0, 0x24);
    memset(obj + 0x30, 0, 0x24);
    memset(obj + 0x54, 0, 0x24);
    memset(obj + 0x78, 0, 0x24);
}

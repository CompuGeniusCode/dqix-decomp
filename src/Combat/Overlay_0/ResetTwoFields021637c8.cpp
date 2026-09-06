#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov000_021637c8
ARM void ResetTwoFields021637c8(void* obj) {
    memset((char*)obj + 0x773c, -1, 4);
    memset((char*)obj + 0x7740, 0, 4);
}

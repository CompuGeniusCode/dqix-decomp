#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0207bcc4
ARM void ClearRegion0207bcc4(char* obj) {
    memset(obj, 0, 4);
    *(int*)(obj + 4) = 0;
    *(short*)(obj + 8) = 0;
    *(short*)(obj + 0xa) = 0;
}

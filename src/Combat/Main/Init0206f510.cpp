#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0206f510
ARM void Init0206f510(char* obj) {
    memset(obj, 0, 4);
    *(int*)(obj + 4) = 0;
    memset(obj + 8, -1, 8);
    memset(obj + 0x10, 0, 0x20);
}

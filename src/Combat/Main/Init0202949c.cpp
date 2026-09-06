#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0202949c
ARM void Init0202949c(char* obj) {
    *(char*)(obj + 0x4) = 0;
    memset(obj + 0x4, 0, 0x30);
    *(int*)(obj + 0x0) = 0;
    *(int*)(obj + 0x34) = 0;
    *(int*)(obj + 0x38) = 0;
}

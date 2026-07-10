#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_0203be8c
ARM void InitStruct0203be8c(char* obj) {
    memset(obj, 0, 0x20);
    obj[0x20] = 0;
    obj[0x21] = 0;
    *(short*)(obj + 0x22) = -1;
    obj[0x24] = 0;
}

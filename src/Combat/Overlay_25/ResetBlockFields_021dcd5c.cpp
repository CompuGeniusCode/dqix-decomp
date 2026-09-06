#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov025_021dcd5c
ARM void ResetBlockFields_021dcd5c(void* obj) {
    char* p = (char*)obj;
    p[0x6e4d] = 0;
    p[0x6e4c] = 0;
    memset(p + 0x6ef0, -1, 10);
    *(short*)(p + 0x6efa) = 0;
}

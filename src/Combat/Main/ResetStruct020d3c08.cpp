#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020d3c08
ARM void ResetStruct020d3c08(char* obj) {
    memset(obj, 0, 0xb4);
    *(int*)(obj + 0xb4) = 0;
}

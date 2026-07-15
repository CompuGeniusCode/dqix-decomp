#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_ov017_021972cc
ARM void ClearBufferAndFlag_021972cc(char* p) {
    memset(p + 0x44b8, 0, 8);
    *(unsigned char*)(p + 0x44c0) = 0;
}

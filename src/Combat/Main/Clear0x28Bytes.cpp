#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_020a0d58
ARM void Clear0x28Bytes(void* p) {
    memset(p, 0, 0x28);
}

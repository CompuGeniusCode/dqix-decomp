#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02044494
ARM bool IsHighByteFF02044494(void* obj, void* src) {
    unsigned short buf;
    memcpy(&buf, src, 2);
    return (buf & 0xff00) == 0xff00;
}

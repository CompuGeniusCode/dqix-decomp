#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069e0c
ARM int WriteCommand0xff02(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff02;
    memcpy(d, &v, 2);
    return 2;
}

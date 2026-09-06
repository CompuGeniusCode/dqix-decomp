#include <globaldefs.h>
#include "std_library_functions.h"

// USA: func_02069884
ARM int WriteCommand0xff1d(void** dst) {
    void* d = *dst;
    unsigned short v = 0xff1d;
    memcpy(d, &v, 2);
    return 2;
}

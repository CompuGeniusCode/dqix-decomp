#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_02204168
ARM void* FillRemainder_02204168(int value, unsigned int end, void* dst, unsigned int start) {
    if (start < end) {
        unsigned int len = end - start;
        VectorizedMemset(dst, value, len);
        dst = (char*)dst + len;
    }
    return dst;
}

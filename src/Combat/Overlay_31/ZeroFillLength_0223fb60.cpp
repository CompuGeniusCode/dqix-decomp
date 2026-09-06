#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov031_0223fb60
ARM void ZeroFillLength_0223fb60(void *dst, unsigned int length) {
    VectorizedMemset(dst, 0, length);
}

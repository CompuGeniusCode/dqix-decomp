#include <globaldefs.h>
#include "System/Memory.h"

extern "C" void func_020c82f0(void* obj, unsigned int len);

// USA: func_020d84f8
ARM unsigned int ClearAndInit020d84f8(void* obj, unsigned int len) {
    VectorizedMemset(obj, 0, len);
    func_020c82f0(obj, len);
    return len;
}

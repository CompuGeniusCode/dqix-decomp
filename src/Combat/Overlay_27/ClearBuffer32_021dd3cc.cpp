#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov027_021dd3cc  (semantic: ClearBuffer32_021dd3cc)
extern "C" ARM void func_ov027_021dd3cc(void* p) {
    VectorizedMemset(p, 0, 0x20);
}

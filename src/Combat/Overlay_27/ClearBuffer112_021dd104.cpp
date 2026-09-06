#include <globaldefs.h>
#include "System/Memory.h"

// USA: func_ov027_021dd104  (semantic: ClearBuffer112_021dd104)
extern "C" ARM void func_ov027_021dd104(void* p) {
    VectorizedMemset(p, 0, 0x70);
}

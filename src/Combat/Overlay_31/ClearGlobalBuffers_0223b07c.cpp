#include <globaldefs.h>
#include "System/Memory.h"

extern void* data_ov031_02290d20;

// USA: func_ov031_0223b07c  (semantic: ClearGlobalBuffers_0223b07c)
extern "C" ARM void func_ov031_0223b07c() {
    VectorizedMemset((char*)data_ov031_02290d20 + 0x100, 0, 0x100);
    VectorizedMemset(data_ov031_02290d20, 0, 0x100);
    *(void**)((char*)data_ov031_02290d20 + 0xab0) = data_ov031_02290d20;
}

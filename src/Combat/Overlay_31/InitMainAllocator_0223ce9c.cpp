#include <globaldefs.h>
#include "System/Memory.h"
#include "Memory/HPXEAllocator.h"

extern "C" void func_020c9be0(void);
extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223ce9c
ARM void InitMainAllocator_0223ce9c(void* a) {
    VectorizedMemset(a, 0, 0x40000);
    HPXEAllocator* p = HPXEAllocator::CreateAtLocation(a, 0x40000, 0);
    data_ov031_02290d3c = p;
    if (p == 0) {
        func_020c9be0();
    }
}

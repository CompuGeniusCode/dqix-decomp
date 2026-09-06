#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

extern "C" int func_020bdc24(void* obj);

struct Obj020bdac0 {
    HMRFAllocator* allocator;   /* 0x00 */
    SignedAllocatorList list;   /* 0x04 */
};

// USA: func_020bdac0
ARM int SaveStateAndAllocateChild020bdac0(struct Obj020bdac0* obj) {
    if (!obj->allocator->SaveCurrentState(obj->list.numElements)) return -1;
    if (func_020bdc24(obj)) return obj->list.numElements - 1;
    obj->allocator->RestoreState(0);
    return -1;
}

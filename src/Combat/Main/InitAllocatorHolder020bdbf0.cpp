#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

extern "C" int func_020bdc24(void* obj);

struct Obj020bdbf0 {
    HMRFAllocator* allocator;   /* 0x00 */
    SignedAllocatorList list;   /* 0x04 */
};

// USA: func_020bdbf0
ARM int InitAllocatorHolder020bdbf0(struct Obj020bdbf0* obj, HMRFAllocator* allocator) {
    obj->list.Initialize(0xc);
    obj->allocator = allocator;
    return func_020bdc24(obj) != 0;
}

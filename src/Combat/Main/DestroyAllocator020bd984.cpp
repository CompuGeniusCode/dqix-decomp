#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

extern "C" void func_020bd99c(void* obj);

struct Obj020bd984 { HMRFAllocator* allocator; };

// USA: func_020bd984
ARM void DestroyAllocator020bd984(struct Obj020bd984* obj) {
    func_020bd99c(obj);
    obj->allocator->RemoveFromTree();
}

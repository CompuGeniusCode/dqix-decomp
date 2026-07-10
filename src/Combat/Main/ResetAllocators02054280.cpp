#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct T02054280 {
    short field0;
    SafeAllocator allocs[10];
};

// USA: func_02054280
ARM void ResetAllocators02054280(struct T02054280* obj) {
    int i;
    obj->field0 = -1;
    for (i = 0; i < 10; i++) {
        obj->allocs[i].ResetAllocatorPointer();
    }
}

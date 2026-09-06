#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct ElementList0208d8ec {
    void* entries;      /* 0x00 */
    short count;        /* 0x04 */
    short capacity;     /* 0x06 */
};

// USA: func_0208d8ec
ARM void InitElementList0208d8ec(struct ElementList0208d8ec* obj, SafeAllocator* alloc, int capacity) {
    if (alloc == NULL) return;
    if (capacity <= 0) return;
    obj->count = 0;
    obj->capacity = capacity;
    obj->entries = alloc->Allocate(capacity * 0x18);
}

#include <globaldefs.h>
#include "Memory/HMRFAllocator.h"

void InitAllocatorListZero(SignedAllocatorList* list);

struct Obj020bdc24 {
    HMRFAllocator* allocator;   /* 0x00 */
    SignedAllocatorList list;   /* 0x04 */
};

// USA: func_020bdc24
// Kept as extern "C" func_020bdc24: sibling callers (e.g. InitAllocatorHolder020bdbf0,
// SaveStateAndAllocateChild020bdac0, and still-undecompiled func_020bd99c/func_020bdb0c)
// reference this symbol directly, so the raw name must be preserved.
extern "C" ARM int func_020bdc24(void* objPtr) {
    struct Obj020bdc24* obj = (struct Obj020bdc24*)objPtr;
    void* p = obj->allocator->Allocate(0x14, 4);
    if (p == NULL) return 0;
    InitAllocatorListZero((SignedAllocatorList*)p);
    obj->list.InsertAtEnd((SignedAllocatorHeader*)p);
    return 1;
}

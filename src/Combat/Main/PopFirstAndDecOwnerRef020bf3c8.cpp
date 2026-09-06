#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

struct RefOwner020bf3c8 {
    char pad0[0x11c];
    int refCount;   /* 0x11c */
};

struct Node020bf3c8 {
    char pad0[8];
    struct RefOwner020bf3c8* owner;  /* 0x8 */
};

// USA: func_020bf3c8
ARM SignedAllocatorHeader* PopFirstAndDecOwnerRef020bf3c8(SignedAllocatorList* list) {
    unsigned int saved = DisableIRQInterrupts();
    SignedAllocatorHeader* e = list->ElementAfter(NULL);
    if (e != NULL) {
        list->Remove(e);
        ((Node020bf3c8*)e)->owner->refCount--;
    }
    SetIRQInterruptState(saved);
    return e;
}

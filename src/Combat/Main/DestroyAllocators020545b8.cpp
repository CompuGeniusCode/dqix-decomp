#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct T020545b8 {
    char pad0[4];
    SafeAllocator allocs[10];
    char pad1[0x460];
    SafeAllocator alloc1;
    SafeAllocator alloc2;
    SafeAllocator alloc3;
    char pad2[0x70];
    SafeAllocator alloc4;
};

// USA: func_020545b8
ARM void DestroyAllocators020545b8(struct T020545b8* obj) {
    int i;
    for (i = 0; i < 10; i++) {
        if (obj->allocs[i].GetSignedAllocator()) {
            obj->allocs[i].Destroy();
        }
    }
    SafeAllocator* arr[4] = { &obj->alloc1, &obj->alloc2, &obj->alloc3, &obj->alloc4 };
    int j;
    for (j = 0; j < 4; j++) {
        SafeAllocator* p = arr[j];
        if (p->GetSignedAllocator()) {
            p->Destroy();
        }
    }
}

#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int data_020e7b98[][4];

struct AllocTarget0204b12c {
    char pad0[0x14];
    void* field14;
    unsigned int field18;
    unsigned char pad1c[3];
    unsigned char field1f;
};

// USA: func_0204b12c
ARM void AllocateAndClearBuffer0204b12c(struct AllocTarget0204b12c* obj, SafeAllocator* alloc) {
    unsigned int size;
    void* p;
    if (alloc == NULL) return;
    size = data_020e7b98[obj->field1f][obj->field18];
    p = alloc->Allocate(size);
    obj->field14 = p;
    memset(p, 0, size);
}

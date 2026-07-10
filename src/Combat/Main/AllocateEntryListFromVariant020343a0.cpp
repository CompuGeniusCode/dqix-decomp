#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct List020346b4;

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void AllocateEntryList020346b4(struct List020346b4* self, SafeAllocator* alloc, int count);

extern void* data_02104b10[2];

// USA: func_020343a0
ARM int AllocateEntryListFromVariant020343a0(struct Variant02030b0c* p) {
    AllocateEntryList020346b4((struct List020346b4*)data_02104b10[1], (SafeAllocator*)data_02104b10[0], GetIntFromVariant02030b0c(p));
    return 1;
}

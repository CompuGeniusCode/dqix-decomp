#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct List020347e8;

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void AllocateList020347e8(struct List020347e8* self, SafeAllocator* alloc, int count);

extern void* data_02104b10[2];

// USA: func_02034478
ARM int AllocateListFromVariant02034478(struct Variant02030b0c* p) {
    AllocateList020347e8((struct List020347e8*)data_02104b10[1], (SafeAllocator*)data_02104b10[0], GetIntFromVariant02030b0c(p));
    return 1;
}

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct Pool02089ea0;

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void AllocateArrayPool02089ea0(struct Pool02089ea0* out, SafeAllocator* alloc, int count);

struct ArrayPoolContext02108efc {
    struct Pool02089ea0* pool;   // 0x0
    int unk4;                    // 0x4
    int unk8;                    // 0x8
    SafeAllocator* alloc;        // 0xc
};
extern ArrayPoolContext02108efc data_02108efc;

// USA: func_02089b64
ARM int InitArrayPoolFromVariant(struct Variant02030b0c* variant) {
    AllocateArrayPool02089ea0(data_02108efc.pool, data_02108efc.alloc, (short)GetIntFromVariant02030b0c(variant));
    return 1;
}

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0204af38 {
    char _pad0[0x10];
    void* buffer;        // 0x10
    char _pad1[0xa];     // 0x14
    unsigned char count; // 0x1e
};

// Allocates the background layer's array of tilemap descriptors: count entries of 0x10 bytes parked
// at +0x10, with the capacity byte written to +0x1e; +0x1d is the number in use, which the indexer
// func_0204af14 and ResetBackgroundLayerTilemaps bound against and func_0204acdc increments.
// Only the SCRN branch of func_0204b174, which memcmps a record's tag against "CHAR", "PALT" and
// "SCRN", fills this array, so the entries are screen chunks and not the other resource kinds;
// calling a descriptor's first two halfwords width and height is still an inference.
extern "C" ARM void AllocateBackgroundLayerTilemaps(struct Foo0204af38* obj, int count, SafeAllocator* alloc) {
    if (alloc == NULL) return;
    obj->buffer = alloc->Allocate(count * 0x10);
    obj->count = count;
}

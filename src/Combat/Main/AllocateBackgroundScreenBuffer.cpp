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

// Allocates and zeroes a background layer's screen (tilemap) buffer and stores it at +0x14. The
// size comes from data_020e7b98 indexed by the layer kind at +0x1f and the size code at +0x18:
// 0x800/0x1000/0x1000/0x2000 for text BGs, 0x200/0x800/0x2000/0x8000 for extended-affine ones,
// each exactly the dimensions in the table at 0x020e7b78 at two bytes per map entry. func_0204b04c
// cache-cleans that same length and func_0204b088 uploads it, so this buffer is what reaches VRAM;
// no symbol names the field.
extern "C" ARM void AllocateBackgroundScreenBuffer(struct AllocTarget0204b12c* obj, SafeAllocator* alloc) {
    unsigned int size;
    void* p;
    if (alloc == NULL) return;
    size = data_020e7b98[obj->field1f][obj->field18];
    p = alloc->Allocate(size);
    obj->field14 = p;
    memset(p, 0, size);
}

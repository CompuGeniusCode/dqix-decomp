#include <globaldefs.h>
struct Block0207df50 { unsigned int v[10]; };
struct Pair0207df50 { unsigned int v[2]; };
struct Foo0207df50 {
    struct Block0207df50 a;   // 0x00
    struct Block0207df50 b;   // 0x28
    unsigned int c;           // 0x50
    unsigned int d;           // 0x54
    struct Pair0207df50 p1;   // 0x58
    struct Pair0207df50 p2;   // 0x60
};
// Rewinds this context's texture VRAM cursors to where they stood before its region was reserved,
// which frees everything allocated inside the region. The struct carries two snapshots of the five
// texture image pools from VRAMAllocations.cpp (freeStart_ and freeEnd_ of each, 0x28 bytes) and
// two of the palette allocator pair data_0210cf88; ReserveTextureVramRegion seeds both before reserving,
// RestoreVramAllocatorCursors installs the working copy at +0x28/+0x60 into the live allocators and SaveVramAllocatorState
// captures it back. Zone3D::SwitchZone calls this before rebuilding a zone.
extern "C" ARM void RewindTextureVramReservation(struct Foo0207df50 *p) {
    p->b = p->a;
    p->p2 = p->p1;
}

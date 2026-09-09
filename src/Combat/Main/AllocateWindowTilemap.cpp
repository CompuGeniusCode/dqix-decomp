#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Obj0204c7a8 {
    char pad0[0x8];
    int field8;
    char pad_c[0xd4 - 0xc];
    void* fieldd4;
};

// Allocates a text window's tilemap. +0xd4 is the halfword-per-tile buffer func_0204e998
// walks -- height rows at +0xaa of width entries at +0xa8, filled with consecutive character
// numbers from +0xa0 shifted right five -- and the one decompiled caller asks for two size
// arguments multiplied together and doubled, one halfword per tile, for an element it has just
// reset with ResetWindowElement. The value stored at +0x8 is not established; that caller takes it
// from the menu-system context and it is never read in anything decompiled so far.
extern "C" ARM void AllocateWindowTilemap(struct Obj0204c7a8* obj, SafeAllocator* alloc, int val, unsigned int len) {
    obj->fieldd4 = alloc->Allocate(len);
    obj->field8 = val;
}

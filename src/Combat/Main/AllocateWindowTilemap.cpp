#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct TextWindow {
    char unknown0[0x8];
    int unknown8;
    char unknownc[0xd4 - 0xc];
    void* tilemap;
};

// Allocates a text window's tilemap. +0xd4 is the halfword-per-tile buffer func_0204e998
// walks -- height rows at +0xaa of width entries at +0xa8, filled with consecutive character
// numbers from +0xa0 shifted right five -- and the one decompiled caller asks for two size
// arguments multiplied together and doubled, one halfword per tile, for an element it has just
// reset with ResetWindowElement. The value stored at +0x8 is not established; that caller,
// func_ov023_021f7da0, reads it out of the menu-system context at +0x9c, ResetWindowElement zeroes
// it along with +0x0 and +0x4, and nothing decompiled reads it back, so it stays unknown8.
extern "C" ARM void AllocateWindowTilemap(struct TextWindow* window, SafeAllocator* alloc, int unknown8Value, unsigned int len) {
    window->tilemap = alloc->Allocate(len);
    window->unknown8 = unknown8Value;
}

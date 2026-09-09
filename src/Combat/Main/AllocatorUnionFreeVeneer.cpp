#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

// A long-branch veneer rather than real code: the three words are "ldr ip, [pc]", "bx ip" and
// the literal 0x020afe80, which symbols.txt gives as AllocatorUnion::Free.
// About 160 sites across arm9 and ten overlays reach Free through it, which is what makes it
// look like a hub. The allocator handed in is usually data_02114e20, the main heap that
// func_02012d18 builds over the HPXE region.
extern "C" ARM void AllocatorUnionFreeVeneer(AllocatorUnion* alloc, void* data) {
    alloc->Free(data);
}

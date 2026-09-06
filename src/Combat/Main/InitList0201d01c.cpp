#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List0201e634;
struct Variant02030b0c;

extern "C" void _ZN12ZoneFeatures23AllocateOpcode6aEntriesEiP13SafeAllocator(List0201e634*, int, SafeAllocator*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Container0201d01c {
    int f0;
    SafeAllocator* alloc; // +0x4
    List0201e634* list;   // +0x8
};
extern Container0201d01c data_020fdc20;

// USA: func_0201d01c
extern "C" ARM int _Z20WarpScript_Opcode_6aPN6Script9ParameterEi(Variant02030b0c* p) {
    _ZN12ZoneFeatures23AllocateOpcode6aEntriesEiP13SafeAllocator(data_020fdc20.list, _ZNK6Script9Parameter5ToIntEv(p), data_020fdc20.alloc);
    return 1;
}

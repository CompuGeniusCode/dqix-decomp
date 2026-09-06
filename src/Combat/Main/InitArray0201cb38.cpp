#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e518;
struct Variant02030b0c;

extern "C" void _ZN12ZoneFeatures23AllocateOpcode68EntriesEiP13SafeAllocator(Foo0201e518*, int, SafeAllocator*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Container0201cb38 {
    int f0;
    SafeAllocator* alloc; // +0x4
    Foo0201e518* array;   // +0x8
};
extern Container0201cb38 data_020fdc20;

// USA: func_0201cb38
extern "C" ARM int _Z20WarpScript_Opcode_68PN6Script9ParameterEi(Variant02030b0c* p) {
    _ZN12ZoneFeatures23AllocateOpcode68EntriesEiP13SafeAllocator(data_020fdc20.array, _ZNK6Script9Parameter5ToIntEv(p), data_020fdc20.alloc);
    return 1;
}

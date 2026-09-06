#include <globaldefs.h>

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e25c;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
extern "C" extern void _ZN12ZoneFeatures23AllocateOpcode64EntriesEiP13SafeAllocator(struct Foo0201e25c*, int, SafeAllocator*);

struct GlobalList020fdc20_c79c {
    int pad0;                  // 0x0
    SafeAllocator* alloc;      // 0x4
    struct Foo0201e25c* array; // 0x8
};
extern struct GlobalList020fdc20_c79c data_020fdc20;

// USA: func_0201c79c
extern "C" ARM int _Z20WarpScript_Opcode_64PN6Script9ParameterEi(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    _ZN12ZoneFeatures23AllocateOpcode64EntriesEiP13SafeAllocator(data_020fdc20.array, n, data_020fdc20.alloc);
    return 1;
}

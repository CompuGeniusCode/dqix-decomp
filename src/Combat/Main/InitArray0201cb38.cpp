#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Foo0201e518;
struct Variant02030b0c;

void AllocateArray0201e518(Foo0201e518*, int, SafeAllocator*);
int GetIntFromVariant02030b0c(Variant02030b0c*);

struct Container0201cb38 {
    int f0;
    SafeAllocator* alloc; // +0x4
    Foo0201e518* array;   // +0x8
};
extern Container0201cb38 data_020fdc20;

// USA: func_0201cb38
ARM int InitArray0201cb38(Variant02030b0c* p) {
    AllocateArray0201e518(data_020fdc20.array, GetIntFromVariant02030b0c(p), data_020fdc20.alloc);
    return 1;
}

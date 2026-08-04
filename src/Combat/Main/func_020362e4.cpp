#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

void ResetAndInitStream02036380(unsigned char* obj);
void InitFieldsWithScale0x1000(int* obj);

struct FieldEntry020362e4 { int words[4]; };
struct SubStruct020362e4 { int field0; FieldEntry020362e4* items; };
struct Cache020362e4 { char pad0[0x24]; SubStruct020362e4* sub; };

// USA: func_020362e4
extern "C" ARM void* func_020362e4(void* obj, SafeAllocator* alloc) {
    Cache020362e4* cache = (Cache020362e4*)alloc->Allocate(0x2c);
    if (cache == 0) return 0;
    ResetAndInitStream02036380((unsigned char*)cache);
    cache->sub = (SubStruct020362e4*)alloc->Allocate(8);
    if (cache->sub == 0) return 0;
    cache->sub->field0 = 4;
    cache->sub->items = (FieldEntry020362e4*)alloc->Allocate(0x40);
    if (cache->sub->items == 0) return 0;
    for (int i = 0; i < 4; i++) {
        InitFieldsWithScale0x1000((int*)&cache->sub->items[i]);
    }
    return cache;
}

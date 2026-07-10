#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List0201e634;
struct Variant02030b0c;

void AllocateList0201e634(List0201e634*, int, SafeAllocator*);
int GetIntFromVariant02030b0c(Variant02030b0c*);

struct Container0201d01c {
    int f0;
    SafeAllocator* alloc; // +0x4
    List0201e634* list;   // +0x8
};
extern Container0201d01c data_020fdc20;

// USA: func_0201d01c
ARM int InitList0201d01c(Variant02030b0c* p) {
    AllocateList0201e634(data_020fdc20.list, GetIntFromVariant02030b0c(p), data_020fdc20.alloc);
    return 1;
}

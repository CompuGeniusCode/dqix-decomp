#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
int GetIntFromVariant02030b0c(Variant02030b0c*);

struct Node0201ebc4 {
    void* buf;   // +0x0
    int f4;      // +0x4
    int count;   // +0x8
};
struct Container0201ebc4 {
    int f0;
    SafeAllocator* alloc; // +0x4
    Node0201ebc4* node;   // +0x8
};
extern Container0201ebc4 data_020fdc40;

// USA: func_0201ebc4
ARM int AllocNode0201ebc4(Variant02030b0c* p) {
    int count = GetIntFromVariant02030b0c(p);
    Node0201ebc4* node = data_020fdc40.node;
    node->buf = data_020fdc40.alloc->Allocate(count * 0xc);
    node->count = count;
    return 1;
}

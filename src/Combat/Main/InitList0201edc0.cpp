#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct List0201f1f0;
struct Variant02030b0c;

void AllocateList0201f1f0(List0201f1f0*, int, SafeAllocator*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(Variant02030b0c*);

struct Container0201edc0 {
    int f0;
    SafeAllocator* alloc; // +0x4
    List0201f1f0* list;   // +0x8
};
extern Container0201edc0 data_020fdc40;

// USA: func_0201edc0
ARM int InitList0201edc0(Variant02030b0c* p) {
    AllocateList0201f1f0(data_020fdc40.list, _ZNK6Script9Parameter5ToIntEv(p), data_020fdc40.alloc);
    return 1;
}

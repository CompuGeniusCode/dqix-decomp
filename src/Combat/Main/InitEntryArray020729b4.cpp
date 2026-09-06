#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Entry020729b4 { short f0; int f4; };
struct Obj020729b4 {
    void* ptr;      // 0x0
    short f4field;  // 0x4
    short f6;       // 0x6
};

// USA: func_020729b4  (semantic: InitEntryArray020729b4)
extern "C" ARM void func_020729b4(Obj020729b4* self, SafeAllocator* alloc, unsigned int count) {
    if (self->ptr != 0) return;
    self->f6 = 0;
    self->f4field = (short)count;
    self->ptr = alloc->Allocate(count * 8);
    for (unsigned short i = 0; i < count; i++) {
        ((short*)self->ptr)[i * 4] = -1;
        *(int*)((char*)self->ptr + i * 8 + 4) = 0;
    }
}

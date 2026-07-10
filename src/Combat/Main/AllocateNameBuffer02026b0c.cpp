#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct Obj02026b0c {
    char pad[0x77a];
    unsigned char count;
    unsigned char pad2;
    void* buffer;
};

// USA: func_02026b0c
ARM void AllocateNameBuffer02026b0c(struct Obj02026b0c* p, int n) {
    int base = func_ov017_0218b5b0();
    SafeAllocator* alloc = (SafeAllocator*)(base + 0x128);
    p->count = n;
    p->buffer = alloc->Allocate((n & 0xff) * 0x1a);
}

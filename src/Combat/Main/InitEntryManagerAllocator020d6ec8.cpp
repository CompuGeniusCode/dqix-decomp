#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Container020d6f44;
void ResetEntryManager020d6f44(Container020d6f44* c);

// USA: func_020d6ec8
ARM void InitEntryManagerAllocator020d6ec8(Container020d6f44* c, SafeAllocator* srcAllocator) {
    ((SafeAllocator*)((char*)c + 0xa28))->ResetAllocatorPointer();
    void* buf = srcAllocator->Allocate(0x6000);
    ((SafeAllocator*)((char*)c + 0xa28))->CreateTypeA(buf, 0x6000);
    ResetEntryManager020d6f44(c);
}

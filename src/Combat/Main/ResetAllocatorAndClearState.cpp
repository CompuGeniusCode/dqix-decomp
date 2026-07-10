#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_0218b5b0(void);

struct Obj0208e4f8 {
    int field0;
    int field4;
    short field8;
    short fielda;
    int fieldc;
};

// USA: func_0208e4f8
ARM void ResetAllocatorAndClearState(struct Obj0208e4f8* p) {
    int base = func_ov017_0218b5b0();
    SafeAllocator* alloc = (SafeAllocator*)(base + 0x1a0);
    alloc->Reset();
    p->field4 = 0;
    p->field8 = 0;
    p->fieldc = 0;
}

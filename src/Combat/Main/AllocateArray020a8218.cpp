#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern SafeAllocator* data_02109fe0;

struct Struct020A8218 {
    void* buffer;              // 0x0
    unsigned short capacity;   // 0x4
    unsigned short count;      // 0x6
};

// USA: func_020a8218
ARM void AllocateArray020a8218(struct Struct020A8218* out, int enable, int count) {
    if (enable == 0 || count == 0) return;
    out->buffer = data_02109fe0->Allocate(count * 0x2c);
    out->capacity = (unsigned short)count;
    out->count = 0;
}

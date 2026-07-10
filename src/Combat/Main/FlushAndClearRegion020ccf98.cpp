#include <globaldefs.h>
#include "System/Memory.h"

void InvalidateInstructionCacheRange(int addr, int size);
void InvalidateDataCacheRange(int addr, int size);

struct Struct_020ccf98 {
    int field0;
    int field4;
    int field8;
    int fieldc;
};

// USA: func_020ccf98
ARM void FlushAndClearRegion020ccf98(struct Struct_020ccf98* obj) {
    int base = obj->field4;
    int off = obj->field8;
    int end = off + obj->fieldc;
    InvalidateInstructionCacheRange(base, end);
    InvalidateDataCacheRange(base, end);
    VectorizedMemset((void*)(base + off), 0, end - off);
}

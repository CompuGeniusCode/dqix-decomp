#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void* func_ov011_021842c8(void* obj);

struct Obj021844f4 {
    char pad[0xb0];
    void* field_b0;
    unsigned int field_b4;
};

// USA: func_ov011_021844f4
ARM int AllocateAndStoreSize_021844f4(Obj021844f4* obj, int unused, unsigned int size) {
    void* target = func_ov011_021842c8(obj);
    if (!target) return 0;
    void* mem = ((SafeAllocator*)((char*)target + 4))->Allocate(size);
    obj->field_b0 = mem;
    if (!mem) return 0;
    obj->field_b4 = size;
    return 1;
}

#include <globaldefs.h>
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

struct Bitfield021f5524 { unsigned int value : 12; };
unsigned int GetValueTimes4_021f5524(struct Bitfield021f5524* obj);

struct Obj021f5448 {
    unsigned int count1 : 12;
    unsigned int count2 : 19;
    unsigned int flag : 1;
    void* field4;
    void* field8;
};

// USA: func_ov023_021f5448
extern "C" ARM int func_ov023_021f5448(struct Obj021f5448* obj, SafeAllocator* alloc, void* src, int cond) {
    if (alloc == 0 || src == 0 || cond == 0) {
        return 0;
    }

    if (alloc != 0 && src != 0) {
        memcpy(obj, src, 4);

        unsigned int size1 = GetValueTimes4_021f5524((struct Bitfield021f5524*)obj);
        unsigned int size2 = obj->count2;

        if (size1 != 0) {
            obj->field4 = alloc->Allocate(size1);
        } else {
            obj->field4 = 0;
        }
        if (size2 != 0) {
            obj->field8 = alloc->Allocate(size2);
        } else {
            obj->field8 = 0;
        }

        if (obj->field4 != 0) {
            memcpy(obj->field4, (char*)src + 4, size1);
        }
        if (obj->field8 != 0) {
            unsigned int off = GetValueTimes4_021f5524((struct Bitfield021f5524*)obj) + 4;
            memcpy(obj->field8, (char*)src + off, size2);
        }

        obj->flag = 1;
    }

    return 1;
}

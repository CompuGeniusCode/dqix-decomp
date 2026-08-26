#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

struct Struct02054f80 {
    int field0;
    int field4;
    SignedAllocatorList arr0[3];
    SignedAllocatorList arr1[3];
    SignedAllocatorList arr2[3];
    SignedAllocatorList list74;
    SignedAllocatorList arr3[3];
    SignedAllocatorList list_a4;
    SignedAllocatorList list_b0;
    SignedAllocatorList list_bc;
    SignedAllocatorList list_c8;
    SignedAllocatorList list_d4;
    SignedAllocatorList list_e0;
    SignedAllocatorList list_ec;
    SignedAllocatorList list_f8;
    SignedAllocatorList list_104;
    SignedAllocatorList list_110;
    SignedAllocatorList list_11c;
};

// USA: func_02054f80
extern "C" ARM void func_02054f80(Struct02054f80* obj) {
    obj->field0 = 0;
    obj->field4 = 0;

    for (int i = 0; i < 3; i++) {
        obj->arr0[i].Initialize(4);
        obj->arr1[i].Initialize(4);
        obj->arr2[i].Initialize(4);
        obj->arr3[i].Initialize(4);
    }

    obj->list74.Initialize(4);
    obj->list_a4.Initialize(4);
    obj->list_b0.Initialize(4);
    obj->list_bc.Initialize(4);
    obj->list_c8.Initialize(4);
    obj->list_d4.Initialize(4);
    obj->list_e0.Initialize(4);
    obj->list_ec.Initialize(4);
    obj->list_f8.Initialize(4);
    obj->list_104.Initialize(4);
    obj->list_110.Initialize(4);
    obj->list_11c.Initialize(4);
}

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

bool AllocateAndInitObject020556dc(void** out, SafeAllocator* alloc);
struct S020556cc;
void StoreThreeFields020556cc(struct S020556cc* p, int a, int b, int c);
extern "C" void func_02056d80(void* p);

struct Obj02055660 {
    void* field0;
    void* field4;
    int field8;
    int fieldc;
};

// USA: func_02055660
ARM int MaybeInit02055660(struct Obj02055660* obj, int p1, int p2, int p3) {
    if (p1 == 0) {
        return 0;
    }
    if (p2 == 0) {
        return 0;
    }
    if (p3 == 0) {
        return 0;
    }
    obj->field0 = (void*)p3;
    obj->field8 = p2;
    obj->fieldc = p1;
    if (AllocateAndInitObject020556dc(&obj->field4, (SafeAllocator*)obj->field0)) {
        StoreThreeFields020556cc((struct S020556cc*)obj->field4, obj->fieldc, obj->field8, (int)obj->field0);
        func_02056d80(obj->field4);
    }
    return 1;
}

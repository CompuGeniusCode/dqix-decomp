#include <globaldefs.h>

extern "C" void* func_ov011_021842c8(void* obj);
extern "C" void* _ZN13SafeAllocator8AllocateEj(void* thisPtr, unsigned int size);

struct S021844a4 { char pad[0x9c]; void* f9c; unsigned int fa0; void* fa4; };

// USA: func_ov011_021844a4
ARM int SetAllocFields_021844a4(struct S021844a4* obj, void* p1, unsigned int size) {
    void* base = func_ov011_021842c8(obj);
    if (base == 0) return 1;
    void* r = _ZN13SafeAllocator8AllocateEj((char*)base + 4, size);
    obj->f9c = r;
    if (r == 0) return 1;
    obj->fa4 = p1;
    obj->fa0 = size;
    return 0;
}

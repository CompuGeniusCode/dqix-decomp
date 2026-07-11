#include <globaldefs.h>

class SafeAllocator;
struct Variant02030b0c;
struct ElementArray020e5850;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void AllocateElementArray020e5850(struct ElementArray020e5850* self, SafeAllocator* alloc, int count);

extern void* data_021536c4[2];

// USA: func_020e5728
ARM int AllocateGlobalElementArray020e5728(struct Variant02030b0c* p) {
    int count = GetIntFromVariant02030b0c(p);
    AllocateElementArray020e5850((struct ElementArray020e5850*)data_021536c4[1],
                                 (SafeAllocator*)data_021536c4[0], count);
    return 1;
}

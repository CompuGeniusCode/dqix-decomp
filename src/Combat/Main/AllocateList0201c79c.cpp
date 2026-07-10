#include <globaldefs.h>

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e25c;

extern int GetIntFromVariant02030b0c(struct Variant02030b0c*);
extern void AllocateArray0201e25c(struct Foo0201e25c*, int, SafeAllocator*);

struct GlobalList020fdc20_c79c {
    int pad0;                  // 0x0
    SafeAllocator* alloc;      // 0x4
    struct Foo0201e25c* array; // 0x8
};
extern struct GlobalList020fdc20_c79c data_020fdc20;

// USA: func_0201c79c
ARM int AllocateList0201c79c(struct Variant02030b0c* v) {
    int n = GetIntFromVariant02030b0c(v);
    AllocateArray0201e25c(data_020fdc20.array, n, data_020fdc20.alloc);
    return 1;
}

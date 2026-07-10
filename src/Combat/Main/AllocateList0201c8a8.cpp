#include <globaldefs.h>

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e288;

extern int GetIntFromVariant02030b0c(struct Variant02030b0c*);
extern void AllocateArray0201e288(struct Foo0201e288*, int, SafeAllocator*);

struct GlobalList020fdc20_c8a8 {
    int pad0;                  // 0x0
    SafeAllocator* alloc;      // 0x4
    struct Foo0201e288* array; // 0x8
};
extern struct GlobalList020fdc20_c8a8 data_020fdc20;

// USA: func_0201c8a8
ARM int AllocateList0201c8a8(struct Variant02030b0c* v) {
    int n = GetIntFromVariant02030b0c(v);
    AllocateArray0201e288(data_020fdc20.array, n, data_020fdc20.alloc);
    return 1;
}

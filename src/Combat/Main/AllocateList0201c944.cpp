#include <globaldefs.h>

class SafeAllocator;
struct Variant02030b0c;
struct Foo0201e480;

extern int GetIntFromVariant02030b0c(struct Variant02030b0c*);
extern void AllocateArray0201e480(struct Foo0201e480*, int, SafeAllocator*);

struct GlobalList020fdc20_c944 {
    int pad0;                  // 0x0
    SafeAllocator* alloc;      // 0x4
    struct Foo0201e480* array; // 0x8
};
extern struct GlobalList020fdc20_c944 data_020fdc20;

// USA: func_0201c944
ARM int AllocateList0201c944(struct Variant02030b0c* v) {
    int n = GetIntFromVariant02030b0c(v);
    AllocateArray0201e480(data_020fdc20.array, n, data_020fdc20.alloc);
    return 1;
}

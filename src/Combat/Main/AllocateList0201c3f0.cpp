#include <globaldefs.h>

struct Variant02030b0c;
struct Foo0201c414;

extern int GetIntFromVariant02030b0c(struct Variant02030b0c*);
extern void AllocateArray0201c414(struct Foo0201c414*, int);

struct GlobalList020fdc14_c3f0 {
    int pad0;                  // 0x0
    int pad4;                  // 0x4
    struct Foo0201c414* array; // 0x8
};
extern struct GlobalList020fdc14_c3f0 data_020fdc14;

// USA: func_0201c3f0
ARM int AllocateList0201c3f0(struct Variant02030b0c* v) {
    int n = GetIntFromVariant02030b0c(v);
    AllocateArray0201c414(data_020fdc14.array, n);
    return 1;
}

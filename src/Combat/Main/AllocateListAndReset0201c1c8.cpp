#include <globaldefs.h>

struct Variant02030b0c;
struct Foo0201c444;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c*);
extern void AllocateArray0201c444(struct Foo0201c444*, int);

struct GlobalList020fdc14 {
    int count;                 // 0x0
    int pad4;                  // 0x4
    struct Foo0201c444* array; // 0x8
};
extern struct GlobalList020fdc14 data_020fdc14;

// USA: func_0201c1c8
ARM int AllocateListAndReset0201c1c8(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    AllocateArray0201c444(data_020fdc14.array, n);
    data_020fdc14.count = 0;
    return 1;
}

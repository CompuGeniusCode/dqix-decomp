#include <globaldefs.h>

struct Variant02030b0c;
struct Foo0207c164;

extern "C" extern int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
extern void AllocateArray0207c164(struct Foo0207c164* obj, int count);

struct Globals0207c084 {
    struct Foo0207c164* array;   // 0x0
};
extern struct Globals0207c084 data_02108e78;

// USA: func_0207c084
ARM int AllocateArrayFromVariant0207c084(struct Variant02030b0c* v) {
    int n = _ZNK6Script9Parameter5ToIntEv(v);
    AllocateArray0207c164(data_02108e78.array, (unsigned short)n);
    return 1;
}

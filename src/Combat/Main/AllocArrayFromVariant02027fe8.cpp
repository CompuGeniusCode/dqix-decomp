#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct Array0202834c;

extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
void AllocateArray0202834c(struct Array0202834c* obj, SafeAllocator* alloc, int count);

struct Globals02027fe8 {
    struct Array0202834c* obj;
    SafeAllocator* alloc;
};
extern struct Globals02027fe8 data_020fdd30;

// USA: func_02027fe8
ARM int AllocArrayFromVariant02027fe8(struct Variant02030b0c* p) {
    int count = _ZNK6Script9Parameter5ToIntEv(p);
    AllocateArray0202834c(data_020fdd30.obj, data_020fdd30.alloc, count);
    return 1;
}

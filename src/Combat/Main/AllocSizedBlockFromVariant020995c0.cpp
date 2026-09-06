#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);

struct Obj020995c0 {
    void* mem;      /* +0 */
    int pad4;       /* +4 */
    int count;      /* +8 */
};
extern struct Obj020995c0* data_02109924;
extern AllocatorUnion data_02114e20;

// USA: func_020995c0
ARM int AllocSizedBlockFromVariant020995c0(struct Variant02030b0c* p) {
    int v = _ZNK6Script9Parameter5ToIntEv(p);
    struct Obj020995c0* obj = data_02109924;
    void* mem = AllocateAligned4(&data_02114e20, v << 4);
    obj->mem = mem;
    obj->count = v;
    return 1;
}

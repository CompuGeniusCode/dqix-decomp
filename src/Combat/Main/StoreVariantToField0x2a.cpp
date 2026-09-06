#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern void* data_02108740[];

// USA: func_0205e03c
ARM int StoreVariantToField0x2a(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108740[1] + 0x2a) = _ZNK6Script9Parameter5ToIntEv(p);
    return 1;
}

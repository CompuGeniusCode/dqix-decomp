#include <globaldefs.h>

struct Variant02030b0c;
extern "C" int _ZNK6Script9Parameter5ToIntEv(struct Variant02030b0c* p);

extern void* data_02108740[];

// USA: func_0205e05c
ARM int StoreVariantToField0x30(struct Variant02030b0c* p) {
    *(int*)((char*)data_02108740[1] + 0x30) = _ZNK6Script9Parameter5ToIntEv(p);
    return 1;
}

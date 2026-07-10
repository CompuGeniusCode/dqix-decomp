#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern void* data_02108740[];

// USA: func_0205e03c
ARM int StoreVariantToField0x2a(struct Variant02030b0c* p) {
    *(short*)((char*)data_02108740[1] + 0x2a) = GetIntFromVariant02030b0c(p);
    return 1;
}

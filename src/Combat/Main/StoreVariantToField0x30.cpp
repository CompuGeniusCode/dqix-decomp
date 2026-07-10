#include <globaldefs.h>

struct Variant02030b0c;
int GetIntFromVariant02030b0c(struct Variant02030b0c* p);

extern void* data_02108740[];

// USA: func_0205e05c
ARM int StoreVariantToField0x30(struct Variant02030b0c* p) {
    *(int*)((char*)data_02108740[1] + 0x30) = GetIntFromVariant02030b0c(p);
    return 1;
}

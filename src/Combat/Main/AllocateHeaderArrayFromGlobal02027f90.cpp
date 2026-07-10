#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct Array020286fc;

int GetIntFromVariant02030b0c(struct Variant02030b0c* p);
void AllocateAndClearHeaderArray020286fc(struct Array020286fc* obj, SafeAllocator* alloc, int count);

struct GlobalObjs020fdd30 {
    struct Array020286fc* obj;
    SafeAllocator* alloc;
};
extern struct GlobalObjs020fdd30 data_020fdd30;

// USA: func_02027f90
ARM int AllocateHeaderArrayFromGlobal02027f90(struct Variant02030b0c* p) {
    AllocateAndClearHeaderArray020286fc(data_020fdd30.obj, data_020fdd30.alloc, GetIntFromVariant02030b0c(p));
    return 1;
}

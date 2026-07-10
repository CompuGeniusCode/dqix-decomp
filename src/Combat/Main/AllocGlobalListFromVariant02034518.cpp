#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Variant02030b0c;
struct List020348b4;

extern int GetIntFromVariant02030b0c(struct Variant02030b0c*);
extern void AllocateList020348b4(struct List020348b4*, SafeAllocator*, int);

struct GlobalListSlot02104b10_4518 {
    SafeAllocator* alloc;       // 0x0
    struct List020348b4* list;  // 0x4
};
extern struct GlobalListSlot02104b10_4518 data_02104b10;

// USA: func_02034518
ARM int AllocGlobalListFromVariant02034518(struct Variant02030b0c* v) {
    int n = GetIntFromVariant02030b0c(v);
    AllocateList020348b4(data_02104b10.list, data_02104b10.alloc, n);
    return 1;
}

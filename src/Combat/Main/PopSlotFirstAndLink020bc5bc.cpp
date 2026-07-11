#include <globaldefs.h>
#include "Memory/SignedAllocator.h"

extern "C" void func_020bd99c(void*);

struct AllocSlot020bc5bc {
    char pad0[0xc];
    SignedAllocatorList list;  /* 0xc */
    char pad2[0xc];
};
extern struct AllocSlot020bc5bc data_0210f824[];

struct Node020bc5bc {
    char pad0[8];
    void* field8;                 /* 0x8 */
    struct Node020bc5bc* fieldC;  /* 0xc */
};

// USA: func_020bc5bc
ARM void* PopSlotFirstAndLink020bc5bc(int index, struct Node020bc5bc* node) {
    Node020bc5bc* e = (Node020bc5bc*)data_0210f824[index].list.ElementAfter(NULL);
    if (e == NULL) return NULL;
    data_0210f824[index].list.Remove((SignedAllocatorHeader*)e);
    e->fieldC = node;
    node->field8 = e;
    func_020bd99c(e->field8);
    return e->field8;
}

#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};
void ResetAndDetach020dfc6c(Struct020dfc40* p);
void TailForward02012da4(AllocatorUnion* alloc, void* data);

struct Slot020e5058 {
    Struct020dfc40 inner;
    unsigned char pad2[4];
};

extern Slot020e5058 data_02153694[2];
extern SafeAllocator data_02153680;
extern int data_02114e20;

// USA: func_020e5094
ARM void ResetSlotsAndDestroySafeAllocator020e5094(void) {
    int i;
    for (i = 0; i < 2; i++) {
        ResetAndDetach020dfc6c(&data_02153694[i].inner);
    }
    void* p = data_02153680.GetSignedAllocator();
    if (p != NULL) {
        TailForward02012da4((AllocatorUnion*)&data_02114e20, p);
        data_02153680.Destroy();
    }
}

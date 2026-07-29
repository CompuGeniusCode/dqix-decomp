#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};

struct Slot020e5058 {
    Struct020dfc40 inner;
    unsigned char pad2[4];
};

extern Slot020e5058 data_02153694[2];
extern SafeAllocator data_02153680;

extern "C" void func_0200ee94(void* obj, int count, int size, void* initFn1, void* initFn2);
void* ResetAndReturnSelf020dfc2c(void* p);
SafeAllocator* ResetAndReturnAllocator(SafeAllocator* alloc);

// USA: func_020e68f4
ARM void InitAllocatorSlots020e68f4(void) {
    func_0200ee94(data_02153694, 2, 0x18, (void*)ResetAndReturnSelf020dfc2c, 0);
    ResetAndReturnAllocator(&data_02153680);
}

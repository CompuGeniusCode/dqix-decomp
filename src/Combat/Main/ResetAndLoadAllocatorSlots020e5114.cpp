#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "Filesystem/FileIO.h"

struct Struct020dfc40 {
    unsigned char pad[0xc];
    short field_c;
    int field_10;
};
void ResetStruct020dfc40(Struct020dfc40* p);

struct Slot020e5114 {
    Struct020dfc40 inner;
    unsigned char pad2[4];
};

extern Slot020e5114 data_02153694[2];
extern SafeAllocator data_02153680;

void ShiftInBitOnGlobalObject();
void CallFunc02030110OnGlobalObject();
void HalveGlobalObjectCounter();

extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

extern char data_020f2dd4;
extern char data_020f2de9;
extern char data_020f2dfa;
extern char data_020f2e0e;

// USA: func_020e5114
ARM int ResetAndLoadAllocatorSlots020e5114(void) {
    data_02153680.Reset();
    ShiftInBitOnGlobalObject();
    CallFunc02030110OnGlobalObject();
    for (int i = 0; i < 2; i++) {
        Slot020e5114* slot = &data_02153694[i];
        ResetStruct020dfc40(&slot->inner);
        unsigned int size;
        void* fileData;
        if (i != 0) {
            fileData = ExtractFileFromGP2((const char*)&data_020f2dd4, (const char*)&data_020f2de9, &size);
        } else {
            fileData = ExtractFileFromGP2((const char*)&data_020f2dfa, (const char*)&data_020f2e0e, &size);
        }
        if (fileData != NULL) {
            func_020dfec0(slot, &data_02153680, fileData, size);
        }
    }
    HalveGlobalObjectCounter();
    return 0;
}

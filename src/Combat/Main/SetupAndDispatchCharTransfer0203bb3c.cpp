#include <globaldefs.h>
#include "System/Cache.h"
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void LoadToMainBGStandardPalette(int src, int dstOffset, unsigned int size);
extern "C" void LoadToSubBGStandardPalette(int src, int dstOffset, unsigned int size);
int DispatchCharTransfer0203b784(int* arr1, int idx, int category, int addr, unsigned int len, unsigned int len2);

extern int data_02105254;

struct Obj0203bb3c {
    unsigned char byte0;
    unsigned char byte1;
    unsigned char byte2;
    unsigned char pad3;
    int field4;
    void* field8;
    char pad2[0x14 - 0xc];
    short field14;
    short field16;
    short field18;
};

// USA: func_0203bb3c
ARM void SetupAndDispatchCharTransfer0203bb3c(struct Obj0203bb3c* obj, char* src, SafeAllocator* allocator, int category, unsigned short arg5) {
    obj->field16 = category;
    obj->field18 = arg5;
    int* p = (int*)&data_02105254;
    memcpy(obj, src, 8);
    src += 8;

    if (obj->byte2 == 0) {
        CleanInvalidateCacheRange(src, 0x20);
        switch (category) {
        case 0: LoadToMainBGStandardPalette((int)src, 0, 0x20); break;
        case 1: LoadToSubBGStandardPalette((int)src, 0, 0x20); break;
        }
        src += 0x20;
        obj->field14 = (short)DispatchCharTransfer0203b784(p, category, arg5, (int)src, obj->field4 << 5, obj->field4);
        src += obj->field4 << 5;
    } else if (obj->byte2 == 1) {
        CleanInvalidateCacheRange(src, 0x200);
        switch (category) {
        case 0: LoadToMainBGStandardPalette((int)src, 0, 0x200); break;
        case 1: LoadToSubBGStandardPalette((int)src, 0, 0x200); break;
        }
        src += 0x200;
        obj->field14 = (short)DispatchCharTransfer0203b784(p, category, arg5, (int)src, obj->field4 << 6, obj->field4);
        src += obj->field4 << 6;
    }

    obj->field8 = allocator->Allocate(obj->byte1 * (obj->byte0 * 2));
    memcpy(obj->field8, src, obj->byte1 * (obj->byte0 * 2));
}

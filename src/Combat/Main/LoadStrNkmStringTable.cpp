#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

struct List0202fec8;

extern "C" {
    void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);
}

extern int strDataBinMenuStrNkmGp2;
extern int strStrNkmLgNat;

struct Obj02092f80 {
    unsigned char pad0[0x2c];
    int field_2c;
    unsigned char pad2c[0x34 - 0x30];
    unsigned char field_34;
    unsigned char field_35;
    unsigned char field_36;
    unsigned char field_37;
};

// Entry zero of the four-handler table at data_020e8d84; each handler is a small state machine
// that advances +0x35 and leaves a result code in +0x34 when it finishes. This one pulls
// str_nkm_<LG>.nat out of data/bin/menu/str_nkm.gp2, and on the single pass through state 1 resets
// the object's own SafeAllocator and rebuilds the table at +0x14 from the loaded file. "nkm" is
// likely nakama, the party members, but only the spelling is established.
extern "C" ARM void LoadStrNkmStringTable(Obj02092f80* obj) {
    int ctx = (int)BackgroundLoader::GetInstance();
    unsigned char state = obj->field_35;

    if (state == 0) {
        obj->field_2c = ((BackgroundLoader*)(ctx))->QueueLoadFileInGP2((const char*)((int)&strDataBinMenuStrNkmGp2), (const char*)((int)&strStrNkmLgNat), (SafeAllocator*)(0));
        obj->field_35++;
    } else if (state == 1) {
        if (((BackgroundLoader*)(ctx))->GetTaskStatus((int)(obj->field_2c))) {
            int out1, out2;
            ((BackgroundLoader*)((struct List0202fec8*)ctx))->GetLoadedFileByID((int)(obj->field_2c), (void**)(&out1), (unsigned int*)(&out2));
            ((SafeAllocator*)obj)->Reset();
            func_020dfec0((char*)obj + 0x14, obj, (void*)out1, (unsigned int)out2);
            ((BackgroundLoader*)(ctx))->RemoveTask((int)(obj->field_2c));
            obj->field_2c = -1;
            obj->field_35++;
        }
    } else if (state == 2) {
        obj->field_34 = 3;
        obj->field_35 = 0;
        if (obj->field_37 & 0x1) obj->field_34 = 1;
        if (!(obj->field_37 & 0x8)) obj->field_37 |= 0x4;
        obj->field_36 = 0;
    }
}

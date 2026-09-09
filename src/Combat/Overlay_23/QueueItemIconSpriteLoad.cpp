#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"

extern "C" void __clear(void* buf, int len);
struct StructDE234_020de234;
extern "C" unsigned short func_020de234(struct StructDE234_020de234* p, int preferMid);
struct InitStruct2075;
extern "C" void func_02075d64(struct InitStruct2075* p);

extern char strDataAniAlQuSpr[];
extern char strDataAniDChrNumSpr_021fdc36[];

// Starts the background load of the icon for the item this entry shows; it returns 4 on the call
// that queues and 6 when the entry has no record at obj+0x4c. The usual path is
// data/ani/d_<c><nnn>.spr, built from the record's packed field at +0x10 the same way ov006 builds
// it; with bit 0x1000 set at +0x774 the fixed data/ani/al_qu.spr is used instead. al_qu is the only
// al_ file in data/ani and has the same 24x24 4bpp header, so it reads as a stand-in icon, but what
// it depicts is not established.
extern "C" ARM int QueueItemIconSpriteLoad(void* obj) {
    int listPtr = (int)BackgroundLoader::GetInstance();
    int ok = 0;

    if (*(void**)((char*)obj + 0x4c) != 0) {
        char buf[0x40];
        __clear(buf, 0x40);

        if ((*(unsigned short*)((char*)obj + 0x774) & 0x1000) != 0) {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = func_020de234(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int raw10 = *(unsigned int*)((char*)s2 + 0x10);
            int percent = (raw10 << 4) >> 0x18;
            sprintf(buf, strDataAniAlQuSpr, percent, val);
        } else {
            struct StructDE234_020de234* sp2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned short val = func_020de234(sp2, 0);
            struct StructDE234_020de234* s2 = *(struct StructDE234_020de234**)((char*)obj + 0x4c);
            unsigned int raw10 = *(unsigned int*)((char*)s2 + 0x10);
            int percent = (raw10 << 4) >> 0x18;
            sprintf(buf, strDataAniDChrNumSpr_021fdc36, percent, val);
        }

        int r = ((BackgroundLoader*)(listPtr))->QueueLoadFile((const char*)((int)buf), (SafeAllocator*)(0));
        *(int*)((char*)obj + 0x738) = r;
        ok = 1;
    }

    if (ok != 0) return 4;

    *(unsigned short*)((char*)obj + 0x774) |= 8;
    func_02075d64(*(struct InitStruct2075**)((char*)obj + 0xc8));
    return 6;
}

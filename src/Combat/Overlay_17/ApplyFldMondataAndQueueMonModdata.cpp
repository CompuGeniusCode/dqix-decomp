#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

extern "C" void* GetMultiplayerState(void);
struct List0202fe68;
struct List0202fec8;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct HalfwordArray* src, struct HalfwordArray* dst);
struct ZeroWordAndByte0206ee60Struct;
extern "C" void func_0206ee60(struct ZeroWordAndByte0206ee60Struct* obj);
struct StreamHeader;
extern "C" void func_0206ee80(void* a, void* b, struct StreamHeader* c, int d, void* e, short f);
extern "C" void func_ov017_021b5648(void* obj);

extern char strDataPrmMonModdataNat_021d7bdc;

struct Obj021b5348 {
    char pad0[8];
    void* sub;
    int key;
    unsigned char field10;
};

struct Sub021b5348 {
    char pad0[0x308];
    unsigned char field308;
};

// Step 7 of the nine-step load chain whose handler table sits at 0x021d6bd8; the dispatcher at
// 0x021b4738 indexes that table with the byte at obj+0x10. Step 6, func_021b5250, sets that byte
// to 7 right after queueing data/prm/fld_mondata.bin, so that is the file collected here. It goes
// to the script runner at sub+0x304 together with the halfwords copied out of sub+0x44 - count-many
// of them, into a twelve-slot buffer. It then queues data/prm/mon_moddata.nat and moves the index
// on to 8, unless the byte at sub+0x308 is zero, in which case func_021b5648 ends the chain early.
extern "C" ARM void ApplyFldMondataAndQueueMonModdata(struct Obj021b5348* obj) {
    void* subEarly;
    GetBattleStruct();
    int list = (int)BackgroundLoader::GetInstance();
    GetMultiplayerState();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    subEarly = obj->sub;
    if (((BackgroundLoader*)((struct List0202fe68*)list))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct List0202fec8*)list))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)func_0209c0c0((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            func_0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)subEarly + 0x304));
            void* ptrB = *(void**)((char*)obj->sub + 0x10);
            func_0206ee80((char*)subEarly + 0x304, ptrB, (struct StreamHeader*)out1, (short)out2, buf, signedCount);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(obj->key));
    obj->key = -1;
    int zero = 0;
    if (((struct Sub021b5348*)subEarly)->field308 > zero) {
        obj->key = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&strDataPrmMonModdataNat_021d7bdc), (SafeAllocator*)(0));
        obj->field10 = 8;
    } else {
        func_ov017_021b5648(obj);
    }
}

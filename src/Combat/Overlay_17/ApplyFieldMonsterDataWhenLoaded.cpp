#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

struct LoaderStatusRef;
struct LoaderFileRef;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct HalfwordArray* src, struct HalfwordArray* dst);
extern "C" void* func_0206efc4(void* obj);
extern "C" void func_0206f230(void* runner, int handler, int fileData, int fileSize, void* ids, int f, int g, int h);

extern char strDataPrmFldMondataBin;

struct LoadChainStep {
    char unknown0[8];
    void* sub;
    int key;
    unsigned char stepIndex;
    char unknown11[3];
    int unknown14;
};

// Waits on the data/prm/fld_mondata.bin read this object queued, and once it lands hands the
// buffer to func_0206f230 along with the halfwords copied out of +0x44 of the sub-object -
// count-many of them into a twelve-slot buffer, and that they are ids is an inference, though
// func_0206f230 does read them back as signed halfwords. It queues the same file again on every
// pass, failed loads included, so the table is re-read, not kept. fld_mondata is the field monster
// data; what func_0206f230 builds out of it is not established, and the 7 written to +0x10 is the
// next step index: the dispatcher at 0x021b4738 indexes the nine-step handler table with that byte.
extern "C" ARM void ApplyFieldMonsterDataWhenLoaded(struct LoadChainStep* obj) {
    GetBattleStruct();
    int loader = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(loader))->GetTaskStatus((int)(obj->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct LoaderStatusRef*)loader))->GetDetailedTaskStatus((int)(obj->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct LoaderFileRef*)loader))->GetLoadedFileByID((int)(obj->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)obj->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)func_0209c0c0((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            sub = (char*)obj->sub;
            func_0206efc4(sub + 0x2f8);
            char* sub2 = (char*)obj->sub;
            func_0206f230(sub + 0x2f8, *(int*)(sub2 + 0x10), out1, out2, buf, signedCount, *(int*)(sub2 + 0x14), obj->unknown14);
        }
    }

    ((BackgroundLoader*)(loader))->RemoveTask((int)(obj->key));
    obj->key = -1;
    obj->key = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataPrmFldMondataBin), (SafeAllocator*)(0));
    obj->stepIndex = 7;
}

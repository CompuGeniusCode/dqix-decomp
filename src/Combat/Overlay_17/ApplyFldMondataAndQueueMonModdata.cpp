#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"

extern "C" void* GetMultiplayerState(void);
struct StatusQueryLoader;
struct FileQueryLoader;
extern "C" void __clear(void* buf, int size);
struct HalfwordArray {
    unsigned short arr[12];
    unsigned short count;
};
extern "C" ARM unsigned short func_0209c0c0(struct HalfwordArray* sourceIds, struct HalfwordArray* destIds);
struct ZeroWordAndByte0206ee60Struct;
extern "C" void func_0206ee60(struct ZeroWordAndByte0206ee60Struct* scriptSlot);
struct StreamHeader;
extern "C" void func_0206ee80(void* callbackObject, void* callbackArg, struct StreamHeader* scriptData, int scriptLength, void* idList, short f);
extern "C" void func_ov017_021b5648(void* loadState);

extern char strDataPrmMonModdataNat_021d7bdc;

struct LoadChainState {
    char unknown0[8];
    void* sub;
    int taskId;
    unsigned char stepIndex;
};

struct LoadChainTarget {
    char unknown0[0x308];
    unsigned char unknown308;
};

// Step 7 of the nine-step load chain whose handler table sits at 0x021d6bd8; the dispatcher at
// 0x021b4738 indexes that table with the byte at +0x10 of the state. Step 6, ApplyFieldMonsterDataWhenLoaded,
// sets that byte to 7 right after queueing data/prm/fld_mondata.bin, so that is the file collected
// here. It goes to the script runner at sub+0x304 together with the halfwords copied out of sub+0x44
// - count-many of them, into the twelve-slot buffer, and that they are ids is an inference carried
// over from step 6. func_0206ee60 clears that runner's word at +0x304 and its byte at +0x308 before
// the script runs, so the byte tested afterwards is whatever the run left there. It then queues
// data/prm/mon_moddata.nat and moves the index on to 8, unless the byte at sub+0x308 is zero, in
// which case func_ov017_021b5648 ends the chain early.
extern "C" ARM void ApplyFldMondataAndQueueMonModdata(struct LoadChainState* loadState) {
    void* subEarly;
    GetBattleStruct();
    int list = (int)BackgroundLoader::GetInstance();
    GetMultiplayerState();
    if (!((BackgroundLoader*)(list))->GetTaskStatus((int)(loadState->taskId))) {
        return;
    }

    subEarly = loadState->sub;
    if (((BackgroundLoader*)((struct StatusQueryLoader*)list))->GetDetailedTaskStatus((int)(loadState->taskId)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct FileQueryLoader*)list))->GetLoadedFileByID((int)(loadState->taskId), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            char* sub = (char*)loadState->sub;
            unsigned short buf[12];
            __clear(buf, 0x18);
            short signedCount = (short)func_0209c0c0((struct HalfwordArray*)(sub + 0x44), (struct HalfwordArray*)buf);
            func_0206ee60((struct ZeroWordAndByte0206ee60Struct*)((char*)subEarly + 0x304));
            void* ptrB = *(void**)((char*)loadState->sub + 0x10);
            func_0206ee80((char*)subEarly + 0x304, ptrB, (struct StreamHeader*)out1, (short)out2, buf, signedCount);
        }
    }

    ((BackgroundLoader*)(list))->RemoveTask((int)(loadState->taskId));
    loadState->taskId = -1;
    int zero = 0;
    if (((struct LoadChainTarget*)subEarly)->unknown308 > zero) {
        loadState->taskId = ((BackgroundLoader*)(list))->QueueLoadFile((const char*)((int)&strDataPrmMonModdataNat_021d7bdc), (SafeAllocator*)(0));
        loadState->stepIndex = 8;
    } else {
        func_ov017_021b5648(loadState);
    }
}

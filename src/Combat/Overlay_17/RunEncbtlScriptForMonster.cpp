#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;

extern "C" char* GetZoneState(void);
extern "C" int func_0201079c(char* battleStruct);
extern "C" int func_020107d0(char* battleStruct);
extern "C" int func_0201b5b0(int monsterId);
extern "C" void func_0209bc98(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char strDataPrmEncbtlBin;

struct ScriptSource_021b4f48 {
    unsigned short monsterId;
    char pad2[0x10 - 0x2];
    int param;
};

struct ScriptRequest_021b4f48 {
    char pad0[8];
    struct ScriptSource_021b4f48* source;
    int taskId;
    unsigned char state;
};

// Steps one data/prm/encbtl.bin request: once the queued load has finished it runs the file as a
// script for the monster id the request names, drops the task and immediately queues encbtl.bin
// again. Monster ids in 0x9c41..0x9ca0 are grotto placeholders and are resolved here against the
// active grotto -- the floor's rank for slot (id % 20), plus the grotto environ times 100, plus
// 0x9c40. "encbtl" is presumably encounter battle, but nothing here establishes that.
extern "C" ARM void RunEncbtlScriptForMonster(struct ScriptRequest_021b4f48* request) {
    struct BattleStruct* battle = GetBattleStruct();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)GetZoneState() + 0x23ec);

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int monsterId = request->source->monsterId;
            int field5cb0 = func_0201079c((char*)battle);
            int field5cb4 = func_020107d0((char*)battle);
            if (func_0201b5b0(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int environ = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (environ * 100 + 0x9c40);
            }
            func_0209bc98(
                (char*)request->source + 0x60, (struct StreamHeader*)data, size,
                request->source->param, monsterId, field5cb0, field5cb4);
        }
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&strDataPrmEncbtlBin, 0);
    request->state = BackgroundLoader::TaskStatus_Fence;
}

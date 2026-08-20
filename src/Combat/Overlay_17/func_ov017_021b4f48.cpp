#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Filesystem/BackgroundLoader.h"
#include "Grotto/Main/ActiveGrottoClass.h"

struct StreamHeader;

extern "C" char* func_02012fe4(void);
extern "C" int _Z17GetField5cb0ValuePc(char* battleStruct);
extern "C" int _Z17GetField5cb4ValuePc(char* battleStruct);
extern "C" int _Z17IsInRange0201b5b0i(int monsterId);
extern "C" void _Z33SetupAndRunBufferedScript0209bc98PvP12StreamHeaderiiiii(
    void* dest, struct StreamHeader* data, int size, int param,
    int monsterId, int field5cb0, int field5cb4);

extern const char data_ov017_021d7b71;

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

// USA: func_ov017_021b4f48
extern "C" ARM void func_ov017_021b4f48(struct ScriptRequest_021b4f48* request) {
    struct BattleStruct* battle = GetBattleStruct();
    BackgroundLoader* loader = BackgroundLoader::GetInstance();
    ActiveGrottoClass* grotto = (ActiveGrottoClass*)((char*)func_02012fe4() + 0x23ec);

    if (loader->GetTaskStatus(request->taskId) == 0) {
        return;
    }
    if (loader->GetDetailedTaskStatus(request->taskId) == BackgroundLoader::TaskStatus_Complete) {
        unsigned int size;
        void* data;
        loader->GetLoadedFileByID(request->taskId, &data, &size);
        if (data != 0) {
            int monsterId = request->source->monsterId;
            int field5cb0 = _Z17GetField5cb0ValuePc((char*)battle);
            int field5cb4 = _Z17GetField5cb4ValuePc((char*)battle);
            if (_Z17IsInRange0201b5b0i(monsterId)) {
                int rank = grotto->GetFloorMonsterRank(monsterId % 20);
                int environ = grotto->GetActiveGrottoEnviron();
                monsterId = rank + (environ * 100 + 0x9c40);
            }
            _Z33SetupAndRunBufferedScript0209bc98PvP12StreamHeaderiiiii(
                (char*)request->source + 0x60, (struct StreamHeader*)data, size,
                request->source->param, monsterId, field5cb0, field5cb4);
        }
    }
    loader->RemoveTask(request->taskId);
    request->taskId = -1;
    request->taskId = loader->QueueLoadFile(&data_ov017_021d7b71, 0);
    request->state = BackgroundLoader::TaskStatus_Fence;
}

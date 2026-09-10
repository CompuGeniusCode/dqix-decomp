#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Combat/Main/BattleList.h"
#include "Filesystem/FileIO.h"

struct LoaderStatusRef;
struct LoaderFileRef;
struct InitStruct;
extern "C" ARM void func_020280b0(struct InitStruct* scriptState);
struct ScriptState;
extern "C" void func_02028104(struct ScriptState* scriptState, int handler, int scriptData, int scriptSize);
extern "C" void func_02028214(void* scriptState, int handler);

extern char data_ov017_021d7b4f;
extern char strDataPrmEncmonsBin;

struct LoadChainStep {
    char unknown0[8];
    void* sub;
    int key;
    unsigned char stepIndex;
    char unknown11[3];
    int unknown14;
};

// Runs the encmons script once its background load reports success. data/prm/encmons.bin is a NARC;
// the member whose name contains "bin" goes to func_02028048 along with the freshly initialized
// structure at sub+0x18, which it publishes in the global opcode handler pair at data_020fdd30
// together with the handler word at sub+0x10, so the script presumably fills it -- func_0202811c
// reads it back -- and sub[0xc] then marks it ready. encmons sits with encfld.bin, encbtl.bin and
// enchab.gp2 in data/prm, so it is presumably the encounter monster table. On the way out it
// removes the task and re-queues the same file, leaving step index 3, the slot the dispatcher at
// 0x021b4738 takes its next handler from; why it reloads is not established.
extern "C" ARM void RunEncmonsScriptWhenLoaded(struct LoadChainStep* loadStep) {
    GetBattleStruct();
    int loader = (int)BackgroundLoader::GetInstance();
    if (!((BackgroundLoader*)(loader))->GetTaskStatus((int)(loadStep->key))) {
        return;
    }

    if (((BackgroundLoader*)((struct LoaderStatusRef*)loader))->GetDetailedTaskStatus((int)(loadStep->key)) == 2) {
        int out2, out1;
        ((BackgroundLoader*)((struct LoaderFileRef*)loader))->GetLoadedFileByID((int)(loadStep->key), (void**)(&out1), (unsigned int*)(&out2));
        if (out1 != 0) {
            unsigned int fileSize;
            const void* filePtr;
            FindFilesInNarcBySubstring((const void*)out1, &data_ov017_021d7b4f, &filePtr, &fileSize, 1);
            if (filePtr != 0) {
                char* sub = (char*)loadStep->sub;
                func_020280b0((struct InitStruct*)(sub + 0x18));
                func_02028104((struct ScriptState*)(sub + 0x18), *(int*)((char*)loadStep->sub + 0x10), (int)filePtr, (int)fileSize);
                func_02028214(sub + 0x18, *(int*)((char*)loadStep->sub + 0x10));
                sub[0xc] = 1;
            }
        }
    }

    ((BackgroundLoader*)(loader))->RemoveTask((int)(loadStep->key));
    loadStep->key = -1;
    loadStep->key = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataPrmEncmonsBin), (SafeAllocator*)(0));
    loadStep->stepIndex = 3;
}

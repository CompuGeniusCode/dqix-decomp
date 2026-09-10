#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int strDataScenarioQuestorder3Bin_020f1474;

struct QuestOrderContext {
    char unknown0[0xa8];
    void* table;
    char unknownac[0x4c4 - 0xa8 - 4];
    int loadTaskId;
};

// Allocates the 0x198-byte block hung off +0xa8 and queues data/scenario/questorder3.bin on the
// background loader, keeping the task id at +0x4c4; it returns 0 only when the allocation fails, so
// the load itself is never checked here. The file's first word is 203 and its second is its own
// length, 10656. It is the only questorder file in the ROM, so the 3 is not a series index. Its one
// caller is in ov004, which fits an ordering used to list quests. func_02095ee0 is the other half:
// it polls that same task id with GetTaskStatus, hands the loaded file to Script::Load and
// Script::Execute, calls RemoveTask and puts -1 back in the id, and gives up early when the block
// at +0xa8 is null, so the block has to be there before the script will run. Nothing decompiled
// reads what the block holds, so that the script is what fills it is only the likeliest reading.
extern "C" ARM int BeginLoadQuestOrderTable(struct QuestOrderContext* questOrder, SafeAllocator* allocator) {
    void* table = allocator->Allocate(0x198);
    questOrder->table = table;
    if (table == NULL) {
        return 0;
    }
    memset(table, 0, 0x198);
    questOrder->loadTaskId = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&strDataScenarioQuestorder3Bin_020f1474), (SafeAllocator*)(0));
    return 1;
}

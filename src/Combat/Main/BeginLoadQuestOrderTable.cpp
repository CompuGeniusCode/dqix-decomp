#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "std_library_functions.h"
#include "Memory/SafeAllocator.h"

extern int strDataScenarioQuestorder3Bin_020f1474;

struct Obj02095e90 {
    char pad[0xa8];
    void* fieldA8;
    char pad2[0x4c4 - 0xa8 - 4];
    int field4c4;
};

// Allocates the 0x198-byte block hung off +0xa8 and queues data/scenario/questorder3.bin on the
// background loader, keeping the task id at +0x4c4; it returns 0 only when the allocation fails, so
// the load itself is never checked here. The file's first word is 203 and its second is its own
// length, 10656. It is the only questorder file in the ROM, so the 3 is not a series index. Its one
// caller is in ov004, which fits an ordering used to list quests.
extern "C" ARM int BeginLoadQuestOrderTable(struct Obj02095e90* obj, SafeAllocator* allocator) {
    void* ptr = allocator->Allocate(0x198);
    obj->fieldA8 = ptr;
    if (ptr == NULL) {
        return 0;
    }
    memset(ptr, 0, 0x198);
    obj->field4c4 = ((BackgroundLoader*)((int)BackgroundLoader::GetInstance()))->QueueLoadFile((const char*)((int)&strDataScenarioQuestorder3Bin_020f1474), (SafeAllocator*)(0));
    return 1;
}

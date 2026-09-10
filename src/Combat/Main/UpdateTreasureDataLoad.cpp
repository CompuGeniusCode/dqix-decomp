#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_02026780(void* self, int a, int b);

struct List0202fec8;

extern int strDataScenarioTreasureNsarc;

// Two-step loader for data/scenario/treasure.nsarc, driven by the request byte at 0x9b8. Step 0
// queues the archive, step 1 waits for it and hands the file to func_02026780, which resets the
// LootableContainerManager allocator and calls LootableContainerManager::LoadZoneContainers
// with a name it takes from GetZoneState. The archive holds 268 members, one
// <mapShortName>.bin per zone (C01.bin, C01M04.bin, ...).
// A nonzero return from the parser sets 0x779, and func_02021578 reads that to raise the
// request again and clear the records, so a failed parse is retried rather than dropped.
// How often this runs is not established: its one caller is func_02022dc8, which nothing in
// the recorded relocations calls.
extern "C" ARM void UpdateTreasureDataLoad(char* self) {
    int loader;
    int treasureNarcData;
    int treasureNarcSize;

    if (*(unsigned char*)(self + 0x9b8) == 0) {
        return;
    }

    loader = (int)BackgroundLoader::GetInstance();

    if (*(unsigned char*)(self + 0x9b9) == 0) {
        ((BackgroundLoader*)(loader))->RemoveTask((int)(*(int*)(self + 0xa2c)));
        ((BackgroundLoader*)((unsigned char*)loader))->AddFence();
        *(int*)(self + 0xa2c) = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataScenarioTreasureNsarc), (SafeAllocator*)(0));
        *(unsigned char*)(self + 0x9b9) += 1;
        return;
    }

    if (*(unsigned char*)(self + 0x9b9) != 1) {
        return;
    }

    if (((BackgroundLoader*)(loader))->GetTaskStatus((int)(*(int*)(self + 0xa2c))) == 0) {
        return;
    }

    treasureNarcData = 0;
    treasureNarcSize = 0;
    ((BackgroundLoader*)((struct List0202fec8*)loader))->GetLoadedFileByID((int)(*(int*)(self + 0xa2c)), (void**)(&treasureNarcData), (unsigned int*)(&treasureNarcSize));

    if (func_02026780(self, treasureNarcData, treasureNarcSize) == 0) {
        *(unsigned char*)(self + 0x9ba) = 1;
    } else {
        *(unsigned char*)(self + 0x779) = 1;
        *(unsigned char*)(self + 0x9ba) = 1;
    }

    ((BackgroundLoader*)(loader))->RemoveTask((int)(*(int*)(self + 0xa2c)));
    *(int*)(self + 0xa2c) = -1;
    *(unsigned char*)(self + 0x9b8) = 0;
    *(unsigned char*)(self + 0x9b9) += 1;
}

#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

int LoadFileIntoMemory(const char* path, void* buffer, unsigned int* outLength);

struct StreamHeader;
struct Obj02071488;
extern "C" int func_02071488(struct StreamHeader* buffer, int length, int assetId, struct Obj02071488* obj);

extern char strDataEvsptLv5EventlistLv5Bin;
extern char strDataEventEvlQuestBin;
extern char strDataEventEventlist6Bin;
extern char fileStagingBuffer;

// Picks the event list for an event id and runs it as a script to fill the caller's record. Ids
// 21000 to 39999 come from data/evspt_lv5/eventlist_lv5.bin, which matches the ev21500..ev29791
// archives sitting in that directory; ids from 40000 up come from data/event/evl_quest.bin and
// everything below from data/event/eventlist6.bin. The staging buffer is shared with other loaders,
// which is presumably why the background loader lock wraps the whole thing rather than each load.
extern "C" ARM struct Obj02071488* RunEventListScriptForEventId(unsigned int value, struct Obj02071488* obj) {
    unsigned int length;

    BackgroundLoader::AddLockGlobal();

    if (value >= 0x5208 && value < 0x9c40) {
        if (LoadFileIntoMemory(&strDataEvsptLv5EventlistLv5Bin, &fileStagingBuffer, &length) &&
            func_02071488((struct StreamHeader*)&fileStagingBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else if (value >= 0x9c40) {
        if (LoadFileIntoMemory(&strDataEventEvlQuestBin, &fileStagingBuffer, &length) &&
            func_02071488((struct StreamHeader*)&fileStagingBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    } else {
        if (LoadFileIntoMemory(&strDataEventEventlist6Bin, &fileStagingBuffer, &length) &&
            func_02071488((struct StreamHeader*)&fileStagingBuffer, length, value, obj)) {
            BackgroundLoader::RemoveLockGlobal();
            return obj;
        }
    }

    BackgroundLoader::RemoveLockGlobal();
    return NULL;
}

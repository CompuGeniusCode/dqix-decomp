#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" void* func_ov011_021849c8(void*);
extern "C" int func_ov023_021f6bb8(void*);
extern "C" void func_ov023_021f6bb0(void*, int);

extern char strDataPrmItemsortGp2_021ff480;
extern char strItemsortLgBin_021ff496;

struct Self021fc2b8 { char pad[0x1c]; int field1c; };

// Asks the background loader for itemsort_<LG>.bin out of data/prm/itemsort.gp2 and parks the task id
// on the sub-object that ov011's func_ov011_021849c8 returns for the caller's argument. A sub-object
// that already carries a non-negative id is left alone and self->field1c is handed back instead, so an
// outstanding request is never reissued. The two return values are not interchangeable, but what
// field1c means is not known.
extern "C" ARM int RequestItemSortTableLoad(struct Self021fc2b8* self, void* arg1) {
    void* sub = func_ov011_021849c8(arg1);
    int v = func_ov023_021f6bb8(sub);
    if (v >= 0) {
        return self->field1c;
    }
    int getter = (int)BackgroundLoader::GetInstance();
    int result = ((BackgroundLoader*)(getter))->QueueLoadFileInGP2((const char*)((int)&strDataPrmItemsortGp2_021ff480), (const char*)((int)&strItemsortLgBin_021ff496), (SafeAllocator*)(0));
    func_ov023_021f6bb0(sub, result);
    return 1;
}

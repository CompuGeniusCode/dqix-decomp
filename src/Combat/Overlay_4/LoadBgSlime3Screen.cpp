#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct BackgroundLoaderInstance;

struct PacEntry;
extern "C" int CountPacEntries(struct PacEntry* entry);

struct PacEntry;
extern "C" void* GetPacEntryByIndex(struct PacEntry* rec, int index, void** out, int* out44);

struct BgLayer;
extern "C" void ResetBackgroundLayer(struct BgLayer* layer);

extern "C" void PrepareBgBlockForUpload(void* layer, char* str);

struct BgLayer;
extern "C" void UploadBgResourceByTag(struct BgLayer* self, char* str);

struct BgLayer {
    unsigned char unknown0[0x1c];
    unsigned char engine : 4;
    unsigned char bgIndex : 4;
    unsigned char unknown1d[3];
};

struct BgSlime3LoadState { char unknown0[0x20]; int handle; int state; };
extern BgSlime3LoadState data_ov004_021707e8;
extern char strDataAniBgSlime3Pac_02170542;

// Two-step loader for data/ani/bg_slime3.pac, which holds no motion resource despite the ani/
// directory: bg_slime.bncg, .bncl and .bnsc are tiles, palette and screen map for one static image.
// The first call zeroes the BG0 and BG1 scroll registers of the sub engine and queues the file, so
// the image lands on the sub screen; later calls poll the task and hand every record in the pac to
// PrepareBgBlockForUpload and UploadBgResourceByTag. The layer descriptor built on the stack is set
// to engine 1, BG 1 - the low and high nibbles at +0x1c that both of those dispatch through - which
// is the same sub-engine BG1 the two scroll registers name. Returns 1 while loading, 0 when done.
// The only reference to this function is a table load at 0x02170494; what the background is for is
// not established.
extern "C" ARM int LoadBgSlime3Screen() {
    int ret = 1;
    int loader = (int)BackgroundLoader::GetInstance();

    if (data_ov004_021707e8.state == 0) {
        *(int*)0x4001010 = 0;
        *(int*)0x4001014 = 0;
        data_ov004_021707e8.handle = ((BackgroundLoader*)(loader))->QueueLoadFile((const char*)((int)&strDataAniBgSlime3Pac_02170542), (SafeAllocator*)(0));
        data_ov004_021707e8.state = data_ov004_021707e8.state + 1;
    } else if (data_ov004_021707e8.state == 1) {
        if (((BackgroundLoader*)(loader))->GetTaskStatus((int)(data_ov004_021707e8.handle))) {
            int recListHead;
            int val2Ignored;
            int dummyOut44;
            void* dummyPtr;
            BgLayer layer;

            ((BackgroundLoader*)((struct BackgroundLoaderInstance*)loader))->GetLoadedFileByID((int)(data_ov004_021707e8.handle), (void**)(&recListHead), (unsigned int*)(&val2Ignored));
            int count = CountPacEntries((struct PacEntry*)recListHead);
            ResetBackgroundLayer((struct BgLayer*)&layer);
            layer.engine = 1;
            layer.bgIndex = 1;
            for (int entryIndex = 0; entryIndex < count; entryIndex++) {
                void* rec = GetPacEntryByIndex((struct PacEntry*)recListHead, entryIndex, &dummyPtr, &dummyOut44);
                if (rec) {
                    PrepareBgBlockForUpload(&layer, (char*)rec);
                    UploadBgResourceByTag((struct BgLayer*)&layer, (char*)rec);
                }
            }
            ((BackgroundLoader*)(loader))->RemoveTask((int)(data_ov004_021707e8.handle));
            data_ov004_021707e8.handle = -1;
            ret = 0;
        }
    }
    return ret;
}

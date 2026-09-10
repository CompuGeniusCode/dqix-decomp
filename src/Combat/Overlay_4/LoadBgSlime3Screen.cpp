#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

struct List0202fec8;

struct ActiveEntry02046900;
extern "C" int CountPacEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
extern "C" void* GetPacEntryByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct List0204af64;
extern "C" void ResetBackgroundLayer(struct List0204af64* obj);

extern "C" void PrepareBgBlockForUpload(void* obj, char* str);

struct SelfTag0204b3a0;
extern "C" void UploadBgResourceByTag(struct SelfTag0204b3a0* self, char* str);

struct LocalListStruct02163144 {
    unsigned char pad0[0x1c];
    unsigned char lo : 4;
    unsigned char hi : 4;
    unsigned char pad1d[3];
};

struct Struct021707e8_02163144 { char pad0[0x20]; int handle; int state; };
extern Struct021707e8_02163144 data_ov004_021707e8;
extern char strDataAniBgSlime3Pac_02170542;

// Two-step loader for data/ani/bg_slime3.pac, which holds no motion resource despite the ani/
// directory: bg_slime.bncg, .bncl and .bnsc are tiles, palette and screen map for one static image.
// The first call zeroes the sub engine's BG0 and BG1 scroll registers and queues the file, so the
// image lands on the sub screen; later calls poll the task and hand every record in the pac to
// PrepareBgBlockForUpload and UploadBgResourceByTag. Returns 1 while loading, 0 when done. Its
// only reference is a table load at 0x02170494; what the background is for is not established.
extern "C" ARM int LoadBgSlime3Screen() {
    int ret = 1;
    int data4 = (int)BackgroundLoader::GetInstance();

    if (data_ov004_021707e8.state == 0) {
        *(int*)0x4001010 = 0;
        *(int*)0x4001014 = 0;
        data_ov004_021707e8.handle = ((BackgroundLoader*)(data4))->QueueLoadFile((const char*)((int)&strDataAniBgSlime3Pac_02170542), (SafeAllocator*)(0));
        data_ov004_021707e8.state = data_ov004_021707e8.state + 1;
    } else if (data_ov004_021707e8.state == 1) {
        if (((BackgroundLoader*)(data4))->GetTaskStatus((int)(data_ov004_021707e8.handle))) {
            int recListHead;
            int val2Ignored;
            int dummyOut44;
            void* dummyPtr;
            LocalListStruct02163144 s;

            ((BackgroundLoader*)((struct List0202fec8*)data4))->GetLoadedFileByID((int)(data_ov004_021707e8.handle), (void**)(&recListHead), (unsigned int*)(&val2Ignored));
            int count = CountPacEntries((struct ActiveEntry02046900*)recListHead);
            ResetBackgroundLayer((struct List0204af64*)&s);
            s.lo = 1;
            s.hi = 1;
            for (int i = 0; i < count; i++) {
                void* rec = GetPacEntryByIndex((struct Rec020467f0*)recListHead, i, &dummyPtr, &dummyOut44);
                if (rec) {
                    PrepareBgBlockForUpload(&s, (char*)rec);
                    UploadBgResourceByTag((struct SelfTag0204b3a0*)&s, (char*)rec);
                }
            }
            ((BackgroundLoader*)(data4))->RemoveTask((int)(data_ov004_021707e8.handle));
            data_ov004_021707e8.handle = -1;
            ret = 0;
        }
    }
    return ret;
}

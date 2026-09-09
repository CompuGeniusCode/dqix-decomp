#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"

extern "C" void func_020c39a0(short* out, int value);

extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void ResetBackgroundLayer(void*);
extern "C" void func_0204b11c(void*, int);
extern "C" void func_0204b5b4(void*, int, void*, int);
extern "C" void AllocateBackgroundScreenBuffer(void*, void*);
extern "C" void func_0204af38(void*, int, void*);
extern "C" void SetBackgroundScroll(void*, int, int);
extern "C" void _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned int*);
extern "C" int CountPacEntries(void*);
extern "C" void* GetPacEntryByIndex(void*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, int);
extern "C" void func_0204b8d0(void*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void UploadTilemapToBGScreen(void*, void*);

extern char strDataMenuNintendoPac;
extern int fileStagingBuffer;

struct ResetContext0218cd98 {
    char pad0[0x470];
    SafeAllocator allocator;
};

// Builds the publisher notice screen. data/menu/nintendo.pac holds a single background image,
// PublishGray_White, as its .bncg, .bncl and .bnsc records; each record of the pac is added to a
// tile surface which is then drawn 0x20 by 0x18 tiles - one whole DS screen - and flushed. The sub
// engine's master brightness register is driven to -16, full black, on the way in and both engines'
// on the way out, so it is the caller that decides when the screen becomes visible.
extern "C" ARM void SetUpNintendoPublisherScreen(struct ResetContext0218cd98* self) {
    unsigned char* base = (unsigned char*)self;

    func_020c39a0((short*)0x400106c, -16);
    self->allocator.Reset();
    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    ResetBackgroundLayer(base + 0xbc + 0x400);
    func_0204b11c(base + 0xbc + 0x400, 0);

    unsigned char* obj = base + 0xbc;
    unsigned char* list = obj + 0x400;
    list[0x1c] = (list[0x1c] & ~0xf) | 1;
    int v2 = list[0x1c] & ~0xf0;
    list[0x1c] = v2;
    func_0204b5b4(list, 0, obj, v2);

    AllocateBackgroundScreenBuffer(base + 0xbc + 0x400, &self->allocator);
    func_0204af38(base + 0xbc + 0x400, 1, &self->allocator);
    SetBackgroundScroll(base + 0xbc + 0x400, 0, 0);
    BackgroundLoader::AddLockGlobal();

    unsigned int local1c = 0;
    _Z18LoadFileIntoMemoryPKcPvPj((const char*)&strDataMenuNintendoPac, (void*)&fileStagingBuffer, &local1c);
    int count = CountPacEntries(&fileStagingBuffer);

    for (int i = 0; i < count; i++) {
        int recSize;
        void* recField;
        void* rec = GetPacEntryByIndex(&fileStagingBuffer, i, &recField, &recSize);
        if (rec != 0) {
            func_0204b174(base + 0xbc + 0x400, rec, &self->allocator, recSize);
        }
    }

    func_0204b8d0(base + 0xbc + 0x400, 0, 0, 0, 0, 0, 0x20, 0x18, 0xffff);
    UploadTilemapToBGScreen(base + 0xbc + 0x400, (void*)0);
    BackgroundLoader::RemoveLockGlobal();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
}

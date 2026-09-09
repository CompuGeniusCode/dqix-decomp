#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void func_020c39a0(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void ResetBackgroundLayer(void*);
extern "C" void func_0204b11c(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void AllocateBackgroundScreenBuffer(void*, void*);
extern "C" void func_0204af38(void*, int, void*);
extern "C" void SetBackgroundScroll(void*, int, int);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void* _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10MaybeResetEv(void*);
extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(void*, const char*, void*);
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(void*, int);
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(void*, int, void**, unsigned int*);
extern "C" int CountPacEntries(void*);
extern "C" void* GetPacEntryByIndex(void*, int, void**, int*);
extern "C" void func_0204b174(void*, void*, void*, int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(void*, int);
extern "C" void func_0204b8d0(void*, unsigned int, int, int, short, short, short, short, unsigned short);
extern "C" void UploadTilemapToBGScreen(void*, void*);
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(void*);

extern char strDataMenuBgMobi2Pac;

struct Triple3 { unsigned int a, b, c; };
extern Triple3 data_ov020_0218d950;
extern Triple3 data_ov020_0218d944;

struct SetupContext0218cf8c {
    char pad0[0x470];
    SafeAllocator allocator;
};

// Builds the title overlay's two 2D layer lists, one on the main engine and one on the sub, out of
// data/menu/bg_mobi_2.pac. data_ov020_0218d950 is {0,2,4} and data_ov020_0218d944 is {1,3,5}, so
// main takes mobi_clip's tiles, palette and screen and sub takes sqen's tiles and palette with
// Screen1.bnsc -- one complete set each. It then reprograms DISPCNT to leave only BG1 on main and
// BG0 on sub, zeroes both BLDCNTs to disable blending, and writes 0x8010 to both MASTER_BRIGHTs
// (mode 2, factor 16), a full brightness fade to black. What "mobi" abbreviates is not established.
extern "C" ARM void SetupBgMobi2Screens(struct SetupContext0218cf8c* self) {
    unsigned char* base = (unsigned char*)self;

    self->allocator.Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 0, 0x1f, 2, 0);

    ResetBackgroundLayer(base + 0x9c + 0x400);
    func_0204b11c(base + 0x9c + 0x400, 0);
    base[0x4b8] = base[0x4b8] & ~0xf;
    base[0x4b8] = (base[0x4b8] & ~0xf0) | 0x10;
    func_0204b5b4(base + 0x9c + 0x400, 0);
    AllocateBackgroundScreenBuffer(base + 0x9c + 0x400, &self->allocator);
    func_0204af38(base + 0x9c + 0x400, 1, &self->allocator);
    SetBackgroundScroll(base + 0x9c + 0x400, 0, 0);

    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 0, 1, 1, 0);

    ResetBackgroundLayer(base + 0xbc + 0x400);
    func_0204b11c(base + 0xbc + 0x400, 0);
    base[0x4d8] = (base[0x4d8] & ~0xf) | 1;
    base[0x4d8] = base[0x4d8] & ~0xf0;
    func_0204b5b4(base + 0xbc + 0x400, 0);
    AllocateBackgroundScreenBuffer(base + 0xbc + 0x400, &self->allocator);
    func_0204af38(base + 0xbc + 0x400, 1, &self->allocator);
    SetBackgroundScroll(base + 0xbc + 0x400, 0, 0);

    int taskId;
    void* loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10MaybeResetEv(loader);
    taskId = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, &strDataMenuBgMobi2Pac, (void*)0);

  retryLoop:
    if (_ZN16BackgroundLoader13GetTaskStatusEi(loader, taskId) == 0) goto waitForLoad;

    void* recFieldScratch;
    void* fileData;
    unsigned int fileLen;
    _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(loader, taskId, &fileData, &fileLen);
    int count = CountPacEntries(fileData);

    void* resultsArray[6];
    int recSizeArray[6];
    for (int idx = 0; idx < count; idx++) {
        resultsArray[idx] = GetPacEntryByIndex(fileData, idx, &recFieldScratch, &recSizeArray[idx]);
    }

    Triple3 table1 = data_ov020_0218d950;
    Triple3 table2 = data_ov020_0218d944;

    int matchCount1 = 0;
    int matchCount2 = 0;

    for (int idx2 = 0; idx2 < count; idx2++) {
        if (idx2 == (&table1.a)[matchCount1]) {
            func_0204b174(base + 0x9c + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount1++;
        }
        if (idx2 == (&table2.a)[matchCount2]) {
            func_0204b174(base + 0xbc + 0x400, resultsArray[idx2], &self->allocator, recSizeArray[idx2]);
            matchCount2++;
        }
    }

    _ZN16BackgroundLoader10RemoveTaskEi(loader, taskId);

    func_0204b8d0(base + 0x9c + 0x400, 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    func_0204b8d0(base + 0xbc + 0x400, 0, 0, 0, 0, 0, 0x20, 0x19, 0);
    UploadTilemapToBGScreen(base + 0x9c + 0x400, (void*)0);
    UploadTilemapToBGScreen(base + 0xbc + 0x400, (void*)0);
    goto afterLoop;
  waitForLoad:
    _ZN16BackgroundLoader14RemoveAllLocksEv(loader);
    goto retryLoop;
  afterLoop:

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x200;
    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
}

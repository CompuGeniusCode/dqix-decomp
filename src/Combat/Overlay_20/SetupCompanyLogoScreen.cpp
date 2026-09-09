#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void func_020c39a0(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void ResetBackgroundLayer(void*);
extern "C" void func_0204b11c(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void func_0204b12c(void*, void*);
extern "C" void func_0204af38(void*, int, void*);
extern "C" void SetBackgroundScroll(void*, int, int);
extern "C" int DisableSubObjVRAMBanks();
extern "C" int DisableSubBGVRAMBanks();
extern "C" void func_020c3984(unsigned int);
extern "C" void MapVRAMBanksToSubObj(unsigned short value);
extern "C" void MapVRAMBanksToSubBG(int);
extern "C" void func_ov020_0218cd64(int, int, int, int, int);
extern "C" void _ZN16BackgroundLoader13AddLockGlobalEv();
extern "C" void _Z18LoadFileIntoMemoryPKcPvPj(const char*, void*, unsigned int*);
extern "C" int CountPacEntries(void*);
extern "C" void* func_020467f0(void*, int, void**, int*);
extern "C" void func_0204b2e0(void*, char*);
extern "C" void func_0204b3a0(void*, char*);
extern "C" void UploadTilemapToBGScreen(void*, void*);
extern "C" void func_0204afb4(void*);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern char strDataMenuBgSqenPac;
extern char strDataMenuBgLv5Pac;
extern int fileStagingBuffer;

struct List0218d32c {
    unsigned char pad[0x1c];
    unsigned char lowNibble : 4;
    unsigned char highNibble : 4;
    unsigned char pad2[3];
};

struct SetupContext0218d32c {
    char pad0[0x470];
    SafeAllocator allocator;
};

// Brings up a boot logo screen: sets up the VRAM banks, both BG engines and the alpha blend, then
// loads data/menu/bg_sqen.pac when mode is 1 and data/menu/bg_lv5.pac otherwise and hands the
// three records inside to the tile list. SetUpNintendoPublisherScreen, immediately before this one, does
// the same for data/menu/nintendo.pac, so the overlay holds three sibling logo builders. In the
// USA filesystem nintendo.pac is 52,080 bytes and bg_lv5.pac 4,464, while bg_sqen.pac is absent --
// Nintendo published the western release, so the mode 1 branch is presumably dead here.
extern "C" ARM void SetupCompanyLogoScreen(struct SetupContext0218d32c* self, int mode) {
    unsigned char* base = (unsigned char*)self;
    unsigned int outLen;
    void* recFieldScratch;
    char* volatile resultsArray[3];
    int sizeArr[3];
    unsigned char list3[0x20];

    self->allocator.Reset();
    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    ResetBackgroundLayer(base + 0x9c + 0x400);
    func_0204b11c(base + 0x9c + 0x400, 0);
    struct List0218d32c* list = (struct List0218d32c*)(base + 0x9c + 0x400);
    list->lowNibble = 0;
    list->highNibble = 1;
    func_0204b5b4(list, 1);
    func_0204b12c(base + 0x9c + 0x400, &self->allocator);
    func_0204af38(base + 0x9c + 0x400, 1, &self->allocator);
    SetBackgroundScroll(base + 0x9c + 0x400, 0, 0);

    DisableSubObjVRAMBanks();
    DisableSubBGVRAMBanks();
    func_020c3984(0);

    volatile unsigned int* reg1000 = (volatile unsigned int*)0x4001000;
    *reg1000 = (*reg1000 & ~0x1f00) | 0x100;
    MapVRAMBanksToSubObj(0x100);

    *reg1000 = (*reg1000 & 0xffcfffef) | 0x10;
    MapVRAMBanksToSubBG(0x80);

    func_ov020_0218cd64(0, 0, 0xe, 0, 0);
    func_ov020_0218cd64(0, 0, 0xf, 0, 0);

    volatile unsigned short* reg1008 = (volatile unsigned short*)0x4001008;
    reg1008[0] = (reg1008[0] & ~3) | 1;
    reg1008[1] = (reg1008[1] & ~3) | 2;
    reg1008[2] = reg1008[2] & ~3;
    reg1008[3] = (reg1008[3] & ~3) | 3;

    _ZN16BackgroundLoader13AddLockGlobalEv();

    if (mode == 1) {
        _Z18LoadFileIntoMemoryPKcPvPj((const char*)&strDataMenuBgSqenPac, (void*)&fileStagingBuffer, &outLen);
    } else {
        _Z18LoadFileIntoMemoryPKcPvPj((const char*)&strDataMenuBgLv5Pac, (void*)&fileStagingBuffer, &outLen);
    }

    int count = CountPacEntries((void*)&fileStagingBuffer);

    for (int i = 0; i < count; i++) {
        resultsArray[i] = (char*)func_020467f0((void*)&fileStagingBuffer, i, &recFieldScratch, &sizeArr[i]);
    }

    ResetBackgroundLayer(list3);
    list3[0x1c] = (list3[0x1c] & ~0xf) | 1;
    list3[0x1c] = list3[0x1c] & ~0xf0;
    func_0204b5b4(list3, 3);
    func_0204b11c(list3, 0);
    SetBackgroundScroll(list3, 0, 0);

    for (int j = 0; j < 3; j++) {
        func_0204b2e0(list3, resultsArray[j]);
        func_0204b3a0(list3, resultsArray[j]);
    }

    UploadTilemapToBGScreen(list3, (void*)0);
    func_0204afb4(list3);
    _ZN16BackgroundLoader16RemoveLockGlobalEv();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;

    func_020c39a0((short*)0x400006c, -16);
    func_020c39a0((short*)0x400106c, -16);
}

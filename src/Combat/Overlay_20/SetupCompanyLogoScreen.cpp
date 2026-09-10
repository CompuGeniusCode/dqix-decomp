#pragma opt_vectorize_loops off
#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "std_library_functions.h"

extern "C" void SetMasterBrightness(short* out, int value);

extern "C" void MapVRAMBanksToMainBG(int);
extern "C" void func_ov020_0218c7bc(int, int, int, int, int);
extern "C" void ResetBackgroundLayer(void*);
extern "C" void SetTextBgScreenSize(void*, int);
extern "C" void func_0204b5b4(void*, int);
extern "C" void AllocateBackgroundScreenBuffer(void*, void*);
extern "C" void AllocateBackgroundLayerTilemaps(void*, int, void*);
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
extern "C" void* GetPacEntryByIndex(void*, int, void**, int*);
extern "C" void PrepareBgBlockForUpload(void*, char*);
extern "C" void UploadBgResourceByTag(void*, char*);
extern "C" void UploadTilemapToBGScreen(void*, void*);
extern "C" void ResetBackgroundLayerTilemaps(void*);
extern "C" void _ZN16BackgroundLoader16RemoveLockGlobalEv();
extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char pixel1Source, unsigned char pixel2Source, unsigned char pixel1Alpha, int pixel2Alpha);

extern char strDataMenuBgSqenPac;
extern char strDataMenuBgLv5Pac;
extern int fileStagingBuffer;

struct BgLayer {
    unsigned char unknown0[0x1c];
    unsigned char engine : 4;
    unsigned char bgIndex : 4;
    unsigned char unknown1d[3];
};

struct TitleScreenContext {
    char unknown0[0x470];
    SafeAllocator allocator;
};

// Brings up a boot logo screen: sets up the VRAM banks, both BG engines and the alpha blend, then
// loads data/menu/bg_sqen.pac when mode is 1 and data/menu/bg_lv5.pac otherwise and hands the
// three records inside to the tile list. SetUpNintendoPublisherScreen at 0x0218cd98 does the same
// for data/menu/nintendo.pac and SetupBgMobi2Screens at 0x0218cf8c sits between the two, so the
// overlay holds three sibling logo builders. In the USA filesystem nintendo.pac is 52,080 bytes
// and bg_lv5.pac 4,464, while bg_sqen.pac is absent -- Nintendo published the western release, so
// the mode 1 branch is presumably dead here.
// The two nibbles at +0x1c of a layer descriptor are the engine and the BG index the upload path
// dispatches on: the context's own descriptor at +0x9c+0x400 is main engine BG1 and the one built
// on the stack is sub engine BG0. The blend call takes two source masks then two alphas, so it is
// BG0 over BG1 at 15 against 0x1f, past the 16 the hardware caps at.
extern "C" ARM void SetupCompanyLogoScreen(struct TitleScreenContext* self, int mode) {
    unsigned char* base = (unsigned char*)self;
    unsigned int outLen;
    void* recFieldScratch;
    char* volatile resultsArray[3];
    int sizeArr[3];
    unsigned char subBgLayer[0x20];

    self->allocator.Reset();
    SetMasterBrightness((short*)0x400006c, -16);
    SetMasterBrightness((short*)0x400106c, -16);
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    ResetBackgroundLayer(base + 0x9c + 0x400);
    SetTextBgScreenSize(base + 0x9c + 0x400, 0);
    struct BgLayer* list = (struct BgLayer*)(base + 0x9c + 0x400);
    list->engine = 0;
    list->bgIndex = 1;
    func_0204b5b4(list, 1);
    AllocateBackgroundScreenBuffer(base + 0x9c + 0x400, &self->allocator);
    AllocateBackgroundLayerTilemaps(base + 0x9c + 0x400, 1, &self->allocator);
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

    for (int entryIndex = 0; entryIndex < count; entryIndex++) {
        resultsArray[entryIndex] = (char*)GetPacEntryByIndex((void*)&fileStagingBuffer, entryIndex, &recFieldScratch, &sizeArr[entryIndex]);
    }

    ResetBackgroundLayer(subBgLayer);
    subBgLayer[0x1c] = (subBgLayer[0x1c] & ~0xf) | 1;
    subBgLayer[0x1c] = subBgLayer[0x1c] & ~0xf0;
    func_0204b5b4(subBgLayer, 3);
    SetTextBgScreenSize(subBgLayer, 0);
    SetBackgroundScroll(subBgLayer, 0, 0);

    for (int recordIndex = 0; recordIndex < 3; recordIndex++) {
        PrepareBgBlockForUpload(subBgLayer, resultsArray[recordIndex]);
        UploadBgResourceByTag(subBgLayer, resultsArray[recordIndex]);
    }

    UploadTilemapToBGScreen(subBgLayer, (void*)0);
    ResetBackgroundLayerTilemaps(subBgLayer);
    _ZN16BackgroundLoader16RemoveLockGlobalEv();

    *(volatile unsigned short*)0x4000050 = 0;
    *(volatile unsigned short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);

    volatile unsigned int* reg0 = (volatile unsigned int*)0x4000000;
    *reg0 = (*reg0 & ~0x1f00) | 0x1300;

    SetMasterBrightness((short*)0x400006c, -16);
    SetMasterBrightness((short*)0x400106c, -16);
}

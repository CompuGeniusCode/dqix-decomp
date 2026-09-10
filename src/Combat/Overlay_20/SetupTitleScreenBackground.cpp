#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" void MapVRAMBanksToMainBG(int v);
extern "C" void MapVRAMBanksToSubBG(int v);
extern "C" void func_ov020_0218c7bc(int a, int b, int c, int d, int e);
extern "C" void func_ov020_0218cd64(int a, int b, int c, int d, int e);
extern "C" void func_0204b5b4(void*, int);
extern "C" void _ZN16BackgroundLoader10RemoveTaskEi(int a, int b);

struct List0202fdd0;
extern "C" int _ZN16BackgroundLoader13GetTaskStatusEi(struct List0202fdd0* obj, int key);

struct Foo0204af38;
extern "C" void func_0204b174(struct Foo0204af38* obj, void* data, SafeAllocator* alloc, int field44);

struct List0204af64;
extern "C" void ResetBackgroundLayer(struct List0204af64* obj);

extern "C" void SetTextBgScreenSize(unsigned char* obj, int value);

struct AllocTarget0204b12c;
extern "C" void AllocateBackgroundScreenBuffer(struct AllocTarget0204b12c* obj, SafeAllocator* alloc);

extern "C" void AllocateBackgroundLayerTilemaps(struct Foo0204af38* obj, int count, SafeAllocator* alloc);

struct Obj0204b5e8;
extern "C" int SetBackgroundScroll(struct Obj0204b5e8* obj, int a, int b);

extern "C" int _ZN16BackgroundLoader11GetInstanceEv();
extern "C" void _ZN16BackgroundLoader10MaybeResetEv(void* objRaw);

extern "C" int _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(int a, int b, int c);

struct List0202fec8;
extern "C" void _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj(struct List0202fec8* obj, int id, int* out1, int* out2);

struct ActiveEntry02046900;
extern "C" int CountPacEntries(struct ActiveEntry02046900* entry);

struct Rec020467f0;
extern "C" void* GetPacEntryByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);

struct Obj0204b8d0;
extern "C" void func_0204b8d0(struct Obj0204b8d0*, unsigned int, int, int, short, short, short, short, unsigned short);

struct List0204b0e8;
extern "C" void UploadTilemapToBGScreen(struct List0204b0e8* obj, void* buf);

struct Obj0202fa00;
extern "C" void _ZN16BackgroundLoader14RemoveAllLocksEv(struct Obj0202fa00* obj);

extern "C" void ColorEffect_ConfigureAlphaBlend(unsigned int* out, unsigned char a, unsigned char b, unsigned char c, int d);

extern "C" void SetMasterBrightness(short* out, int value);

extern int data_ov020_0218d95c;
extern int data_ov020_0218d968;
extern int strDataAniBgTitlePac;

struct RecordIndexTriple {
    int index0, index1, index2;
};

struct TitleScreenState {
    char unknown0[0x4b8];
    unsigned char unknown4b8Low : 4;
    unsigned char unknown4b8High : 4;
    char unknown4b9[0x4d8 - 0x4b9];
    unsigned char unknown4d8Low : 4;
    unsigned char unknown4d8High : 4;
};

// Brings up the title screen background. Both display engines get a BG bank and a list, then
// data/ani/bg_title.pac is loaded synchronously - the loop spins on the task rather than
// returning - and its records are handed out by the two index tables at 0x0218d95c, which is
// 0, 2, 3, and 0x0218d968, which is 1, 2, 4.
// The archive holds five members in that order: bg_title_main.bncg, bg_title_sub.bncg,
// bg_title.bncl, bg_title_main.bnsc and bg_title_sub.bnsc. So the main engine gets the _main
// character and screen data, the sub engine the _sub pair, and record 2 - the shared .bncl
// palette - goes to both.
// The tail programs BLDCNT/BLDALPHA on both screens and clears MASTER_BRIGHT.
extern "C" ARM void SetupTitleScreenBackground(void* titleScreen) {
    char* titleScreenBytes = (char*)titleScreen;

    ((SafeAllocator*)(titleScreenBytes + 0x470))->Reset();
    MapVRAMBanksToMainBG(8);
    func_ov020_0218c7bc(0, 1, 1, 1, 0);

    ResetBackgroundLayer((struct List0204af64*)(titleScreenBytes + 0x49c));
    SetTextBgScreenSize((unsigned char*)(titleScreenBytes + 0x49c), 0);
    ((struct TitleScreenState*)titleScreen)->unknown4b8Low = 0;
    ((struct TitleScreenState*)titleScreen)->unknown4b8High = 1;
    func_0204b5b4(titleScreenBytes + 0x49c, 1);
    AllocateBackgroundScreenBuffer((struct AllocTarget0204b12c*)(titleScreenBytes + 0x49c), (SafeAllocator*)(titleScreenBytes + 0x470));
    AllocateBackgroundLayerTilemaps((struct Foo0204af38*)(titleScreenBytes + 0x49c), 1, (SafeAllocator*)(titleScreenBytes + 0x470));
    SetBackgroundScroll((struct Obj0204b5e8*)(titleScreenBytes + 0x49c), 0, 0);

    MapVRAMBanksToSubBG(4);
    func_ov020_0218cd64(0, 1, 1, 1, 0);

    ResetBackgroundLayer((struct List0204af64*)(titleScreenBytes + 0x4bc));
    SetTextBgScreenSize((unsigned char*)(titleScreenBytes + 0x4bc), 0);
    ((struct TitleScreenState*)titleScreen)->unknown4d8Low = 1;
    ((struct TitleScreenState*)titleScreen)->unknown4d8High = 0;
    func_0204b5b4(titleScreenBytes + 0x4bc, 0);
    AllocateBackgroundScreenBuffer((struct AllocTarget0204b12c*)(titleScreenBytes + 0x4bc), (SafeAllocator*)(titleScreenBytes + 0x470));
    AllocateBackgroundLayerTilemaps((struct Foo0204af38*)(titleScreenBytes + 0x4bc), 1, (SafeAllocator*)(titleScreenBytes + 0x470));
    SetBackgroundScroll((struct Obj0204b5e8*)(titleScreenBytes + 0x4bc), 0, 0);

    int titleBgLoadHandle;
    int loader = _ZN16BackgroundLoader11GetInstanceEv();
    _ZN16BackgroundLoader10MaybeResetEv((void*)loader);
    titleBgLoadHandle = _ZN16BackgroundLoader13QueueLoadFileEPKcP13SafeAllocator(loader, (int)&strDataAniBgTitlePac, 0);

    for (;;) {
        if (_ZN16BackgroundLoader13GetTaskStatusEi((struct List0202fdd0*)loader, titleBgLoadHandle)) {
            void* unusedRecordOut;
            int titleBgFile, titleBgFileSize;
            _ZN16BackgroundLoader17GetLoadedFileByIDEiPPvPj((struct List0202fec8*)loader, titleBgLoadHandle, &titleBgFile, &titleBgFileSize);
            int count = CountPacEntries((struct ActiveEntry02046900*)titleBgFile);
            void* records[5];
            int arrayB[5];
            for (int recordIndex = 0; recordIndex < count; recordIndex++) {
                records[recordIndex] = GetPacEntryByIndex((struct Rec020467f0*)titleBgFile, recordIndex, &unusedRecordOut, &arrayB[recordIndex]);
            }

            int mainTableIndex = 0;
            struct RecordIndexTriple mainScreenRecordIndices = *(struct RecordIndexTriple*)&data_ov020_0218d95c;
            struct RecordIndexTriple subScreenRecordIndices = *(struct RecordIndexTriple*)&data_ov020_0218d968;
            int subTableIndex = 0;
            for (int assignIndex = 0; assignIndex < count; assignIndex++) {
                if (assignIndex == ((int*)&mainScreenRecordIndices)[mainTableIndex]) {
                    func_0204b174((struct Foo0204af38*)(titleScreenBytes + 0x9c + 0x400), records[assignIndex], (SafeAllocator*)(titleScreenBytes + 0x470), arrayB[assignIndex]);
                    mainTableIndex++;
                }
                if (assignIndex == ((int*)&subScreenRecordIndices)[subTableIndex]) {
                    func_0204b174((struct Foo0204af38*)(titleScreenBytes + 0xbc + 0x400), records[assignIndex], (SafeAllocator*)(titleScreenBytes + 0x470), arrayB[assignIndex]);
                    subTableIndex++;
                }
            }

            _ZN16BackgroundLoader10RemoveTaskEi(loader, titleBgLoadHandle);

            func_0204b8d0((struct Obj0204b8d0*)(titleScreenBytes + 0x49c), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
            func_0204b8d0((struct Obj0204b8d0*)(titleScreenBytes + 0x4bc), 0, 0, 0, 0, 0, 0x20, 0x19, 0);
            UploadTilemapToBGScreen((struct List0204b0e8*)(titleScreenBytes + 0x49c), 0);
            UploadTilemapToBGScreen((struct List0204b0e8*)(titleScreenBytes + 0x4bc), 0);
            break;
        }
        _ZN16BackgroundLoader14RemoveAllLocksEv((struct Obj0202fa00*)loader);
    }

    *(short*)0x4000050 = 0;
    *(short*)0x4001050 = 0;
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4000050, 1, 2, 0xf, 0x1f);
    ColorEffect_ConfigureAlphaBlend((unsigned int*)0x4001050, 1, 2, 0x1f, 0);

    *(unsigned int*)0x4000000 = (*(unsigned int*)0x4000000 & ~0x1f00) | 0x300;
    *(unsigned int*)0x4001000 = (*(unsigned int*)0x4001000 & ~0x1f00) | 0x100;
    SetMasterBrightness((short*)0x400006c, 0);
    SetMasterBrightness((short*)0x400106c, 0);
}

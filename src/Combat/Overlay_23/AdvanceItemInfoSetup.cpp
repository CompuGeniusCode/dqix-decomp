#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

struct BattleStruct* GetBattleStruct(void);
extern "C" int func_0200fb8c(int* battleStruct);

extern "C" int func_ov023_021ddbb8(void* itemInfo, int level, int frames);
struct ItemInfoContext;
extern "C" int func_ov023_021ddbf8(struct ItemInfoContext* itemInfo);
extern "C" void func_020dc2bc(void);
extern "C" int func_02094a00(void);
extern "C" void func_02094b30(int, int, int);
extern "C" int func_02094b4c(void);

struct SubBgControlBackup;
extern "C" void func_02074b64(struct SubBgControlBackup* backup);
extern "C" void SaveMainBGControlRegisters(void* backup);

struct LoaderFileRef;
struct PacEntry;
extern "C" int CountPacEntries(struct PacEntry* entry);
struct PacArchive;
extern "C" void* GetPacEntryByIndex(struct PacArchive* rec, int index, void** out, int* out44);
extern "C" void LoadNitroResourceBySignature(void* dest, void* data, int size, void* allocator);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

extern "C" void func_ov023_021dcc58(void* itemInfo);
extern "C" ARM void func_ov023_021db2e4(volatile int* taskIdSlot);

extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct SharedWorkBuffers { unsigned int unknown0; void* workBuffer; };
extern struct SharedWorkBuffers data_ov023_021ff9e0;

extern int strDataAniOiijGp2;
extern int strOiijLgPac;
extern int strDataAniOiirGp2;
extern int strOiirLgPac;
extern int strDataBinMenuStrIiGp2;
extern int strStrIiLgNat;

// Advances the item info setup one step per call, the step at +0x777 and +0x776 going up when it is
// ready. Names are abbreviated: data/ani/oiir.gp2 holds the localised oiir_<LG>.pac and its
// unpacked sibling data/ani/obj_ii.pac holds obj_iteminfo.NCGR, .NCLR and .NCER, with the strings
// in data/bin/menu/str_ii.gp2, so "oii" and "ii" are item info; unused oiij.gp2 next door is
// unexplained. Every pac entry is registered separately, hence the count-then-index pair. The last
// step keeps the five display-layer enable bits of DISPCNT at +0x730, sub engine when +0x77c is 1,
// and hands the eight task-id slots at +0x734 and +0x738 to func_021db2e4, which drops any task
// still outstanding. The 0x1800 buffer allocated once into the ov023 global is the one
// func_021ddc34 installs at +0x8 of whatever object it is handed; what the word before it holds is
// not established.
extern "C" ARM void AdvanceItemInfoSetup(void* objRaw) {
    char* itemInfo = (char*)objRaw;
    int loader = (int)BackgroundLoader::GetInstance();
    func_0200fb8c((int*)GetBattleStruct());

    if (*(unsigned char*)(itemInfo + 0x777) == 0) {
        if (data_ov023_021ff9e0.workBuffer == 0) {
            data_ov023_021ff9e0.workBuffer = AllocateRoundedToWord(&data_02114e20, 0x1800);
        }
        if (!(*(unsigned short*)(itemInfo + 0x774) & 0x40)) {
            *(unsigned char*)(itemInfo + 0x777) = 2;
            return;
        }
        if (*(signed char*)(itemInfo + 0x77b) != 1) {
            func_ov023_021ddbb8(itemInfo, ~0xf, 8);
        }
        *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
    }

    if (*(unsigned char*)(itemInfo + 0x777) == 1) {
        if (func_ov023_021ddbf8((struct ItemInfoContext*)itemInfo) == 0) {
            if (*(signed char*)(itemInfo + 0x77b) != 1) {
                func_020dc2bc();
            }
            *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(itemInfo + 0x777) == 2) {
        if (*(unsigned short*)(itemInfo + 0x774) & 0x10) {
            *(unsigned char*)(itemInfo + 0x777) = 4;
            return;
        }
        int g = func_02094a00();
        func_02094b30(g, 0x1fa, 0);
        *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
    } else if (*(unsigned char*)(itemInfo + 0x777) == 3) {
        func_02094a00();
        if (func_02094b4c() != 0) {
            *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(itemInfo + 0x777) == 4) {
        if (*(signed char*)(itemInfo + 0x77c) == 1) {
            func_02074b64((struct SubBgControlBackup*)(itemInfo + 0x118));
        } else {
            SaveMainBGControlRegisters(itemInfo + 0x118);
        }
        *(char*)(itemInfo + 0x17c) = *(signed char*)(itemInfo + 0x77c);
        *(void**)(itemInfo + 0x16c) = itemInfo + 0x180;
        *(short*)(itemInfo + 0x178) = 30;
        *(int*)(itemInfo + 0x734) = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)((int)&strDataAniOiirGp2), (const char*)((int)&strOiirLgPac), (SafeAllocator*)(0));
        *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
    } else if (*(unsigned char*)(itemInfo + 0x777) == 5) {
        if (((BackgroundLoader*)(loader))->GetTaskStatus((int)(*(int*)(itemInfo + 0x734))) != 0) {
            ((SafeAllocator*)(*(void**)(itemInfo + 0x44)))->Reset();
            void* dummyOut;
            int out1, out2;
            int fieldOut;
            ((BackgroundLoader*)((struct LoaderFileRef*)loader))->GetLoadedFileByID((int)(*(int*)(itemInfo + 0x734)), (void**)(&out1), (unsigned int*)(&out2));
            if (out1 != 0 && out2 != 0) {
                int count = CountPacEntries((struct PacEntry*)out1);
                for (int entryIndex = 0; entryIndex < count; entryIndex++) {
                    void* result = GetPacEntryByIndex((struct PacArchive*)out1, entryIndex, &dummyOut, &fieldOut);
                    LoadNitroResourceBySignature(itemInfo + 0x12c, result, fieldOut, *(void**)(itemInfo + 0x44));
                }
            }
            *(signed char*)(itemInfo + 0x77d) = 1;
            ((BackgroundLoader*)(loader))->RemoveTask((int)(*(int*)(itemInfo + 0x734)));
            *(int*)(itemInfo + 0x734) = -1;
            *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(itemInfo + 0x777) == 6) {
        *(int*)(itemInfo + 0x734) = ((BackgroundLoader*)(loader))->QueueLoadFileInGP2((const char*)((int)&strDataBinMenuStrIiGp2), (const char*)((int)&strStrIiLgNat), (SafeAllocator*)(0));
        *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
    } else if (*(unsigned char*)(itemInfo + 0x777) == 7) {
        if (((BackgroundLoader*)(loader))->GetTaskStatus((int)(*(int*)(itemInfo + 0x734))) != 0) {
            int out1b, out2b;
            ((BackgroundLoader*)((struct LoaderFileRef*)loader))->GetLoadedFileByID((int)(*(int*)(itemInfo + 0x734)), (void**)(&out1b), (unsigned int*)(&out2b));
            ((SafeAllocator*)(itemInfo + 0x14))->Reset();
            if (out1b != 0 && out2b != 0) {
                func_020dfec0(itemInfo + 0x54, itemInfo + 0x14, (void*)out1b, (unsigned int)out2b);
            }
            ((BackgroundLoader*)(loader))->RemoveTask((int)(*(int*)(itemInfo + 0x734)));
            *(int*)(itemInfo + 0x734) = -1;
            *(unsigned char*)(itemInfo + 0x777) = *(unsigned char*)(itemInfo + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(itemInfo + 0x777) == 8) {
        unsigned int dispcnt;
        if (*(signed char*)(itemInfo + 0x77c) == 1) {
            dispcnt = *(volatile unsigned int*)0x4001000;
        } else {
            dispcnt = *(volatile unsigned int*)0x4000000;
        }
        *(int*)(itemInfo + 0x730) = (dispcnt & 0x1f00) >> 8;
        if (*(signed char*)(itemInfo + 0x77b) != 1) {
            func_ov023_021dcc58(itemInfo);
        }
        *(unsigned char*)(itemInfo + 0x776) = 1;
        *(unsigned char*)(itemInfo + 0x777) = 0;
        func_ov023_021db2e4((volatile int*)(itemInfo + 0x734));
        for (int taskSlot = 0; taskSlot < 7; taskSlot++) {
            func_ov023_021db2e4((volatile int*)(itemInfo + 0x738 + taskSlot * 4));
        }
        *(int*)(itemInfo + 0x754) = 0;
        *(unsigned short*)(itemInfo + 0x774) |= 1;
    }
}

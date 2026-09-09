#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

struct BattleStruct* GetBattleStruct(void);
extern "C" int func_0200fb8c(int* obj);

extern "C" int func_ov023_021ddbb8(void* obj, int a, int b);
struct Obj021ddbf8;
extern "C" int func_ov023_021ddbf8(struct Obj021ddbf8* obj);
extern "C" void func_020dc2bc(void);
extern "C" int func_02094a00(void);
extern "C" void func_02094b30(int, int, int);
extern "C" int func_02094b4c(void);

struct SubBgControlBackup02074b64;
extern "C" void func_02074b64(struct SubBgControlBackup02074b64* obj);
extern "C" void SaveMainBGControlRegisters(void* p);

struct List0202fec8;
struct ActiveEntry02046900;
extern "C" int CountPacEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
extern "C" void* GetPacEntryByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void LoadNitroResourceBySignature(void* a, void* ptr, int val, void* d);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

extern "C" void func_ov023_021dcc58(void* obj);
extern "C" ARM void func_ov023_021db2e4(volatile int* p);

extern "C" void* AllocateRoundedToWord(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct DataStruct_021dd59c { unsigned int pad0; void* field4; };
extern struct DataStruct_021dd59c data_ov023_021ff9e0;

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
// step keeps the five display-layer enable bits of DISPCNT at +0x730, sub engine when +0x77c is 1.
extern "C" ARM void AdvanceItemInfoSetup(void* objRaw) {
    char* obj = (char*)objRaw;
    int dataResult = (int)BackgroundLoader::GetInstance();
    func_0200fb8c((int*)GetBattleStruct());

    if (*(unsigned char*)(obj + 0x777) == 0) {
        if (data_ov023_021ff9e0.field4 == 0) {
            data_ov023_021ff9e0.field4 = AllocateRoundedToWord(&data_02114e20, 0x1800);
        }
        if (!(*(unsigned short*)(obj + 0x774) & 0x40)) {
            *(unsigned char*)(obj + 0x777) = 2;
            return;
        }
        if (*(signed char*)(obj + 0x77b) != 1) {
            func_ov023_021ddbb8(obj, ~0xf, 8);
        }
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    }

    if (*(unsigned char*)(obj + 0x777) == 1) {
        if (func_ov023_021ddbf8((struct Obj021ddbf8*)obj) == 0) {
            if (*(signed char*)(obj + 0x77b) != 1) {
                func_020dc2bc();
            }
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 2) {
        if (*(unsigned short*)(obj + 0x774) & 0x10) {
            *(unsigned char*)(obj + 0x777) = 4;
            return;
        }
        int g = func_02094a00();
        func_02094b30(g, 0x1fa, 0);
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 3) {
        func_02094a00();
        if (func_02094b4c() != 0) {
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 4) {
        if (*(signed char*)(obj + 0x77c) == 1) {
            func_02074b64((struct SubBgControlBackup02074b64*)(obj + 0x118));
        } else {
            SaveMainBGControlRegisters(obj + 0x118);
        }
        *(char*)(obj + 0x17c) = *(signed char*)(obj + 0x77c);
        *(void**)(obj + 0x16c) = obj + 0x180;
        *(short*)(obj + 0x178) = 30;
        *(int*)(obj + 0x734) = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&strDataAniOiirGp2), (const char*)((int)&strOiirLgPac), (SafeAllocator*)(0));
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 5) {
        if (((BackgroundLoader*)(dataResult))->GetTaskStatus((int)(*(int*)(obj + 0x734))) != 0) {
            ((SafeAllocator*)(*(void**)(obj + 0x44)))->Reset();
            void* dummyOut;
            int out1, out2;
            int fieldOut;
            ((BackgroundLoader*)((struct List0202fec8*)dataResult))->GetLoadedFileByID((int)(*(int*)(obj + 0x734)), (void**)(&out1), (unsigned int*)(&out2));
            if (out1 != 0 && out2 != 0) {
                int count = CountPacEntries((struct ActiveEntry02046900*)out1);
                for (int i = 0; i < count; i++) {
                    void* result = GetPacEntryByIndex((struct Rec020467f0*)out1, i, &dummyOut, &fieldOut);
                    LoadNitroResourceBySignature(obj + 0x12c, result, fieldOut, *(void**)(obj + 0x44));
                }
            }
            *(signed char*)(obj + 0x77d) = 1;
            ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x734)));
            *(int*)(obj + 0x734) = -1;
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 6) {
        *(int*)(obj + 0x734) = ((BackgroundLoader*)(dataResult))->QueueLoadFileInGP2((const char*)((int)&strDataBinMenuStrIiGp2), (const char*)((int)&strStrIiLgNat), (SafeAllocator*)(0));
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 7) {
        if (((BackgroundLoader*)(dataResult))->GetTaskStatus((int)(*(int*)(obj + 0x734))) != 0) {
            int out1b, out2b;
            ((BackgroundLoader*)((struct List0202fec8*)dataResult))->GetLoadedFileByID((int)(*(int*)(obj + 0x734)), (void**)(&out1b), (unsigned int*)(&out2b));
            ((SafeAllocator*)(obj + 0x14))->Reset();
            if (out1b != 0 && out2b != 0) {
                func_020dfec0(obj + 0x54, obj + 0x14, (void*)out1b, (unsigned int)out2b);
            }
            ((BackgroundLoader*)(dataResult))->RemoveTask((int)(*(int*)(obj + 0x734)));
            *(int*)(obj + 0x734) = -1;
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 8) {
        unsigned int val;
        if (*(signed char*)(obj + 0x77c) == 1) {
            val = *(volatile unsigned int*)0x4001000;
        } else {
            val = *(volatile unsigned int*)0x4000000;
        }
        *(int*)(obj + 0x730) = (val & 0x1f00) >> 8;
        if (*(signed char*)(obj + 0x77b) != 1) {
            func_ov023_021dcc58(obj);
        }
        *(unsigned char*)(obj + 0x776) = 1;
        *(unsigned char*)(obj + 0x777) = 0;
        func_ov023_021db2e4((volatile int*)(obj + 0x734));
        for (int i = 0; i < 7; i++) {
            func_ov023_021db2e4((volatile int*)(obj + 0x738 + i * 4));
        }
        *(int*)(obj + 0x754) = 0;
        *(unsigned short*)(obj + 0x774) |= 1;
    }
}

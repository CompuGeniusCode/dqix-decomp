#include <globaldefs.h>
#include "Memory/AllocatorUnion.h"
#include "Memory/SafeAllocator.h"

int GetData02104304Field4(void);
struct BattleStruct* GetBattleStruct(void);
int GetWord0x0(int* obj);

int DispatchByMode77c_021ddbb8(void* obj, int a, int b);
struct Obj021ddbf8;
int Check_021ddbf8(struct Obj021ddbf8* obj);
void OrGlobalFlag0x40(void);
int GetGlobal02109400(void);
extern "C" void _Z21BlankFunction02094b30v(int, int, int);
int AlwaysTrue02094b4c(void);

struct SubBgControlBackup02074b64;
void BackupSubBgControlRegisters(struct SubBgControlBackup02074b64* obj);
extern "C" void func_02074af4(void* p);
int CallFunc0202fa38Mode2(int a, int b, int c, int d);

extern "C" int func_0202fdd0(int listPtr, int handle);
struct List0202fec8;
void GetListEntryValues0202fec8(struct List0202fec8* obj, int id, int* out1, int* out2);
struct ActiveEntry02046900;
int CountActiveEntries(struct ActiveEntry02046900* entry);
struct Rec020467f0;
void* FindRecordByIndex(struct Rec020467f0* rec, int index, void** out, int* out44);
extern "C" void func_0205a528(void* a, void* ptr, int val, void* d);
extern "C" void func_020301c8(int listPtr, int handle);
extern "C" void func_020dfec0(void* dest, void* allocator, void* fileData, unsigned int size);

void ConfigureBgSub1AndClear_021dcc58(void* obj);
ARM void ResetIfNonNeg_021db2e4(volatile int* p);

void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct DataStruct_021dd59c { unsigned int pad0; void* field4; };
extern struct DataStruct_021dd59c data_ov023_021ff9e0;

extern int data_ov023_021fdb40;
extern int data_ov023_021fdb52;
extern int data_ov023_021fdb60;
extern int data_ov023_021fdb72;
extern int data_ov023_021fdb80;
extern int data_ov023_021fdb99;

// USA: func_ov023_021dd59c
ARM void UpdateCombatOverlayState_021dd59c(void* objRaw) {
    char* obj = (char*)objRaw;
    int dataResult = GetData02104304Field4();
    GetWord0x0((int*)GetBattleStruct());

    if (*(unsigned char*)(obj + 0x777) == 0) {
        if (data_ov023_021ff9e0.field4 == 0) {
            data_ov023_021ff9e0.field4 = AllocateAligned4(&data_02114e20, 0x1800);
        }
        if (!(*(unsigned short*)(obj + 0x774) & 0x40)) {
            *(unsigned char*)(obj + 0x777) = 2;
            return;
        }
        if (*(signed char*)(obj + 0x77b) != 1) {
            DispatchByMode77c_021ddbb8(obj, ~0xf, 8);
        }
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    }

    if (*(unsigned char*)(obj + 0x777) == 1) {
        if (Check_021ddbf8((struct Obj021ddbf8*)obj) == 0) {
            if (*(signed char*)(obj + 0x77b) != 1) {
                OrGlobalFlag0x40();
            }
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 2) {
        if (*(unsigned short*)(obj + 0x774) & 0x10) {
            *(unsigned char*)(obj + 0x777) = 4;
            return;
        }
        int g = GetGlobal02109400();
        _Z21BlankFunction02094b30v(g, 0x1fa, 0);
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 3) {
        GetGlobal02109400();
        if (AlwaysTrue02094b4c() != 0) {
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 4) {
        if (*(signed char*)(obj + 0x77c) == 1) {
            BackupSubBgControlRegisters((struct SubBgControlBackup02074b64*)(obj + 0x118));
        } else {
            func_02074af4(obj + 0x118);
        }
        *(char*)(obj + 0x17c) = *(signed char*)(obj + 0x77c);
        *(void**)(obj + 0x16c) = obj + 0x180;
        *(short*)(obj + 0x178) = 30;
        *(int*)(obj + 0x734) = CallFunc0202fa38Mode2(dataResult, (int)&data_ov023_021fdb60, (int)&data_ov023_021fdb72, 0);
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 5) {
        if (func_0202fdd0(dataResult, *(int*)(obj + 0x734)) != 0) {
            ((SafeAllocator*)(*(void**)(obj + 0x44)))->Reset();
            void* dummyOut;
            int out1, out2;
            int fieldOut;
            GetListEntryValues0202fec8((struct List0202fec8*)dataResult, *(int*)(obj + 0x734), &out1, &out2);
            if (out1 != 0 && out2 != 0) {
                int count = CountActiveEntries((struct ActiveEntry02046900*)out1);
                for (int i = 0; i < count; i++) {
                    void* result = FindRecordByIndex((struct Rec020467f0*)out1, i, &dummyOut, &fieldOut);
                    func_0205a528(obj + 0x12c, result, fieldOut, *(void**)(obj + 0x44));
                }
            }
            *(signed char*)(obj + 0x77d) = 1;
            func_020301c8(dataResult, *(int*)(obj + 0x734));
            *(int*)(obj + 0x734) = -1;
            *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
        }
    }

    if (*(unsigned char*)(obj + 0x777) == 6) {
        *(int*)(obj + 0x734) = CallFunc0202fa38Mode2(dataResult, (int)&data_ov023_021fdb80, (int)&data_ov023_021fdb99, 0);
        *(unsigned char*)(obj + 0x777) = *(unsigned char*)(obj + 0x777) + 1;
    } else if (*(unsigned char*)(obj + 0x777) == 7) {
        if (func_0202fdd0(dataResult, *(int*)(obj + 0x734)) != 0) {
            int out1b, out2b;
            GetListEntryValues0202fec8((struct List0202fec8*)dataResult, *(int*)(obj + 0x734), &out1b, &out2b);
            ((SafeAllocator*)(obj + 0x14))->Reset();
            if (out1b != 0 && out2b != 0) {
                func_020dfec0(obj + 0x54, obj + 0x14, (void*)out1b, (unsigned int)out2b);
            }
            func_020301c8(dataResult, *(int*)(obj + 0x734));
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
            ConfigureBgSub1AndClear_021dcc58(obj);
        }
        *(unsigned char*)(obj + 0x776) = 1;
        *(unsigned char*)(obj + 0x777) = 0;
        ResetIfNonNeg_021db2e4((volatile int*)(obj + 0x734));
        for (int i = 0; i < 7; i++) {
            ResetIfNonNeg_021db2e4((volatile int*)(obj + 0x738 + i * 4));
        }
        *(int*)(obj + 0x754) = 0;
        *(unsigned short*)(obj + 0x774) |= 1;
    }
}

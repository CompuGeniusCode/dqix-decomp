#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct BattleStruct* GetBattleStruct();
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
int GetFieldIfFlag4(char* obj);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
extern int data_ov017_021d8474;
struct Obj02092aa4;
void InitObj02092aa4(struct Obj02092aa4* obj, unsigned char param);
void CreateTypeAFromAllocator(SafeAllocator* self, SafeAllocator* src);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
extern "C" int func_02092bcc(void*, unsigned int);
extern "C" int func_02092b34(void*);
extern "C" void func_ov017_021c0160(void*);
void ClearFlagBits(unsigned char* obj, int mask);
void SetByteField0x253(void* obj);

struct Obj021c01a4 {
    char pad0[0x1];
    unsigned char errorFlag;   // 0x1
    char pad2[0x6];
    SafeAllocator allocator;  // 0x8, size 0x14
    int state;                // 0x1c
    signed char field20;      // 0x20
};

// USA: func_ov017_021c01a4
extern "C" ARM void func_ov017_021c01a4(struct Obj021c01a4* self) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    unsigned char* field = (unsigned char*)GetFieldIfFlag4((char*)battleStruct);
    SetFlagsAt0x244(field, 1);

    if (self->state == 0) {
        func_020a0cc4(0xc3c);
        void* buf = AllocateAligned4(&data_02114e20, 0xc3c);
        if (buf == NULL) {
            func_020a0c0c();
            self->errorFlag = 1;
            return;
        }
        self->allocator.CreateTypeA(buf, 0xc3c);
        self->allocator.Reset();
        void* p = self->allocator.Allocate(0x3c);
        data_ov017_021d8474 = (int)p;
        if (p == NULL) {
            func_020a0c0c();
            self->errorFlag = 1;
            return;
        }
        InitObj02092aa4((struct Obj02092aa4*)p, self->field20);
        CreateTypeAFromAllocator((SafeAllocator*)data_ov017_021d8474, &self->allocator);
        self->state++;
        return;
    } else if (self->state == 1) {
        unsigned int scaleCount = GetBattleScaleCount(GetBattleStruct());
        if (func_02092bcc((void*)data_ov017_021d8474, scaleCount) != 0) {
            self->state++;
        }
        return;
    } else if (self->state == 2) {
        func_02092b34((void*)data_ov017_021d8474);
        self->state++;
        return;
    } else if (self->state == 3) {
        func_ov017_021c0160(self);
        ClearFlagBits(field, 1);
        SetByteField0x253(combatant);
        self->state++;
        self->errorFlag = 1;
        func_020a0c0c();
        return;
    }
}

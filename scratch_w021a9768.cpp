#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

extern "C" void* func_ov017_0218b5b0(void);
extern "C" void* func_0202ae18(void);
struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);
void SetBitsInField4(unsigned int* field, unsigned int bits);
extern "C" void func_020a0cc4(unsigned int);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;
extern "C" void func_020a0c0c(void);
struct ResetObj020d7a5c;
ResetObj020d7a5c* GetGlobalResetObj020d7a50(void);
struct Obj020d7aa0;
void TeardownAndResetState020d7aa0(Obj020d7aa0* obj);
void PushInputLogB(int id);
extern "C" void func_020a1940(int);
extern "C" void func_ov008_02188f5c(void* p, int a, int b);
struct Layout02189284;
void SetupAllocators_02189284(Layout02189284* obj, SafeAllocator* alloc);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
struct Manager0218936c;
unsigned char Dispatch0218936c(Manager0218936c* obj);
struct SearchStruct;
int TestFlagBitAt0xe(struct SearchStruct* obj, int value);
extern "C" void func_ov008_0218b240(void* p);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_ov008_021894b8(void* p);
void SetByteField0x253(void* obj);
void PopStack1AndTrigger(int flag);
extern "C" void func_ov017_021a9714(void* obj);
void ClearBitsInField4(unsigned int* field, unsigned int bits);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);

struct Obj021a9768 {
    unsigned char field0;
    unsigned char field1;
    unsigned char pad2[6];
    unsigned char field8;
    unsigned char pad9;
    unsigned char pada[0x16];
    void* field20;
    signed char field24;
    unsigned char pad25[0x2f];
    int field54;
};

// USA: func_ov017_021a9768
extern "C" ARM void func_ov017_021a9768(Obj021a9768* self) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    unsigned int* field4 = (unsigned int*)func_ov017_0218b5b0();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    struct SearchStruct* search = (struct SearchStruct*)func_0202ae18();
    CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    SetBitsInField4(field4, 0xc0);

    int state = self->field8;
    if (state == 0) {
        func_020a0cc4(0x1c70c);
        void* mem = AllocateAligned4(&data_02114e20, 0x1c70c);
        if (mem == 0) {
            func_020a0c0c();
            self->field1 = 1;
            return;
        }
        TeardownAndResetState020d7aa0((Obj020d7aa0*)GetGlobalResetObj020d7a50());
        ((SafeAllocator*)((char*)self + 0xc))->CreateTypeA(mem, 0x1c70c);
        ((SafeAllocator*)((char*)self + 0xc))->Reset();
        PushInputLogB(1);
        func_020a1940(8);
        self->field20 = ((SafeAllocator*)((char*)self + 0xc))->Allocate(0xecc);
        if (self->field54 == 0) {
            func_ov008_02188f5c(self->field20, self->field24, 0);
        } else {
            func_ov008_02188f5c(self->field20, -1, self->field54);
        }
        SetupAllocators_02189284((Layout02189284*)self->field20, (SafeAllocator*)((char*)self + 0xc));
        self->field8++;
        return;
    }

    if (state == 1) {
        GetBattleScaleCount(battleStruct);
        unsigned char r = Dispatch0218936c((Manager0218936c*)self->field20);
        if (r != 0) {
            self->field8++;
        }
        if (TestFlagBitAt0xe(search, 0)) {
            func_ov008_0218b240(self->field20);
        }
        int inRange = (self->field24 >= 0 && self->field24 <= 3);
        if (!inRange) return;
        if (GetCombatantUnchecked(battleStruct, self->field24) != 0) {
            if (!TestFlagBitAt0xe(search, self->field24)) return;
        }
        func_ov008_0218b240(self->field20);
        return;
    }
    if (state == 2) {
        func_ov008_021894b8(self->field20);
        self->field8++;
        return;
    }
    if (state == 3) {
        struct BattleStruct* bs2 = GetBattleStruct();
        struct CombatantStruct* c2 = GetCombatantAtField0x397c(bs2);
        SetByteField0x253(c2);
        unsigned int layerVal = *(unsigned int*)((char*)self->field20 + 0x14);
        *(unsigned int*)0x4000000 = (*(unsigned int*)0x4000000 & ~0x1f00) | (layerVal << 8);
        self->field20 = 0;
        PopStack1AndTrigger(1);
        func_ov017_021a9714(self);
        func_020a0c0c();
        ClearBitsInField4(field4, 0x80);
        self->field1 = 1;
        return;
    }
}

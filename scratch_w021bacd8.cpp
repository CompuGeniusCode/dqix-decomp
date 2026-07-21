#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Memory/AllocatorUnion.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
int GetFieldIfFlag4(char* obj);
unsigned int GetBattleScaleCount(struct BattleStruct* battleStruct);
void SetBitsInField4(unsigned int* obj, unsigned int mask);
void ClearBitsInField4(unsigned int* obj, unsigned int mask);
void SetFlagsAt0x244(unsigned char* obj, unsigned char mask);
void ClearFlagBits(unsigned char* obj, int mask);
void SetByteField0x253(void* obj);
void PushInputLogA(int id);
void* AllocateAligned4(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion data_02114e20;

struct Obj020397cc;
void CancelPendingAction020397cc(struct Obj020397cc* obj, int arg1);

extern "C" void* func_ov017_0218b5b0(void);
extern "C" int func_ov017_021959b4(void);
extern "C" void func_ov017_021bac8c(void*);
extern "C" void func_020a0cc4(unsigned int);
extern "C" void func_020a0c0c(void);
extern "C" void func_ov003_0215c650(void*);
extern "C" void func_ov003_0215c568(void*, void*);
extern "C" void func_ov003_0215caa4(void*);
extern "C" int func_ov003_0215c924(void*, int);
extern "C" void func_ov003_0215c800(void*);

struct Obj021bacd8 {
    char pad0;
    unsigned char flag1;
    char pad2[6];
    int state;
    SafeAllocator allocator;
    void* field20;
};

// USA: func_ov017_021bacd8
extern "C" ARM void func_ov017_021bacd8(struct Obj021bacd8* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    unsigned int* field4 = (unsigned int*)func_ov017_0218b5b0();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battle);
    unsigned char* flagResult = (unsigned char*)GetFieldIfFlag4((char*)battle);
    SetBitsInField4(field4, 0xc0);
    CancelPendingAction020397cc((struct Obj020397cc*)combatant, 1);
    SetFlagsAt0x244(flagResult, 3);
    unsigned int scale = GetBattleScaleCount(battle);
    int state = obj->state;
    if ((int)scale < 0) scale = 1;

    if (state == 0) {
        func_020a0cc4(0xf43c);
        void* buf = AllocateAligned4(&data_02114e20, 0xf43c);
        if (buf == NULL) {
            func_020a0c0c();
            obj->flag1 = 1;
            return;
        }
        obj->allocator.CreateTypeA(buf, 0xf43c);
        obj->allocator.Reset();
        void* mem = obj->allocator.Allocate(0x3fc);
        obj->field20 = mem;
        if (mem == NULL) {
            func_020a0c0c();
            obj->flag1 = 1;
            return;
        }
        PushInputLogA(3);
        func_ov003_0215c650(obj->field20);
        func_ov003_0215c568(obj->field20, &obj->allocator);
        obj->state = obj->state + 1;
        return;
    }
    if (state == 1) {
        if (func_ov017_021959b4() != 0) {
            func_ov003_0215caa4(obj->field20);
        }
        if (func_ov003_0215c924(obj->field20, scale) != 0) {
            obj->state = obj->state + 1;
        }
        return;
    }
    if (state == 2) {
        func_ov003_0215c800(obj->field20);
        obj->state = obj->state + 1;
        return;
    }
    if (state != 3) {
        return;
    }
    func_ov017_021bac8c(obj);
    ClearBitsInField4(field4, 0xc0);
    SetByteField0x253(combatant);
    ClearFlagBits(flagResult, 3);
    func_020a0c0c();
    obj->flag1 = 1;
}

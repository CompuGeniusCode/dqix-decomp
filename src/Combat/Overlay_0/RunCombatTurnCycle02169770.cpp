#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Memory/SafeAllocator.h"
#include "Util/Random.h"

extern "C" void func_0202ae18(void);
int GetField0x3acValue(struct BattleStruct* battleStruct);
void SeedRandom32Wrapper_0215faa4(struct Random* random, unsigned int stateHi, unsigned int stateLo);
extern "C" void func_ov000_02169850(void* obj);
extern "C" void ProcessCombatTurn(void* a, void* allocator);
extern "C" void func_ov000_0215e6e8(void* p);
void ClearCombatWorkFlags0x55f4(void* work, int mask);
extern "C" void func_ov000_02160e48(void* obj);
extern "C" void* func_0205ec34(void);
void SetOrClearBitInArray(void* unused, unsigned char* array, int bit, int value);
void* GetPtrField0x2a04(struct BattleStruct* battleStruct);
void EnqueueEventTag23Field_021d0d58(void);

// USA: func_ov000_02169770
ARM void RunCombatTurnCycle02169770(unsigned char* obj) {
    struct BattleStruct* battle = GetBattleStruct();
    func_0202ae18();
    void* ptr29c = *(void**)(obj + 0x29c);
    GetField0x3acValue(battle);
    SeedRandom32Wrapper_0215faa4((struct Random*)ptr29c,
        *(unsigned int*)(obj + 0x6000 + 0xe3c),
        *(unsigned int*)(obj + 0x6000 + 0xe40));
    func_ov000_02169850(obj);
    ((class SafeAllocator*)(obj + 0x30))->Reset();

    if (*(unsigned char*)(obj + 0x5000 + 0x950) != 2) {
        ProcessCombatTurn(ptr29c, obj + 0x30);
        func_ov000_0215e6e8(ptr29c);
    }

    ((class SafeAllocator*)(obj + 0x30))->Reset();
    *(unsigned char*)(obj + 0x5000 + 0x950) = 1;
    ClearCombatWorkFlags0x55f4(obj, 0x800000);
    func_ov000_02160e48(obj);

    if (*(int*)((char*)*(int**)(obj + 0x2a0) + 0xc) == 0x19 &&
        *(signed char*)((char*)*(void**)(obj + 0x29c) + 0x8e00 + 0x14) == 1) {
        void* ctx = func_0205ec34();
        SetOrClearBitInArray(ctx, (unsigned char*)ctx + 0x8c, 3, 1);
        *(int*)((char*)GetPtrField0x2a04(battle) + 0x2000 + 0xc94) = 0x6d;
        EnqueueEventTag23Field_021d0d58();
    }
}

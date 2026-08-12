#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" void* func_0202ae18(void* ctx);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
extern "C" void* func_ov017_0218b5b0(void* self);
struct ListHead02046b60;
int ListContainsId(struct ListHead02046b60* list, int id);
int GetGlobalField0x1c020421a0();
void EnqueueEventTag153_021d079c(unsigned char a, unsigned char b, unsigned short c);

struct Obj021b996c { char pad[0x12c]; int field12c; };

// USA: func_ov017_021b996c  (semantic: DispatchEventTag153ByListState_021b996c)
extern "C" ARM void func_ov017_021b996c(struct Obj021b996c* self, int combatantId, int checkVal, unsigned char tag, unsigned short arg5) {
    void* search = func_0202ae18(self);
    signed char cur = GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
    if (checkVal != cur && checkVal != 4) return;

    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, combatantId);
    struct CombatantStruct* combatant2 = GetCombatantAtField0x397c(battle);
    unsigned short u1 = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
    unsigned short u2 = GetU16At0x6((struct U16Field0x6_020375f8*)combatant2);
    if (u1 != u2) {
        EnqueueEventTag153_021d079c(tag, 1, 1);
        return;
    }

    int field5724;
    if (self->field12c != arg5 && (field5724 = *(int*)((char*)battle + 0x5724)) != arg5) {
        void* p = func_ov017_0218b5b0((void*)field5724);
        struct ListHead02046b60* list = *(struct ListHead02046b60**)((char*)p + 0x3000 + 0x6fc);
        if (ListContainsId(list, 4)) {
            EnqueueEventTag153_021d079c(tag, 1, 0);
        } else {
            EnqueueEventTag153_021d079c(tag, 1, 1);
        }
        return;
    }

    int g = GetGlobalField0x1c020421a0();
    if (*(int*)(g + 0x998) != 0) {
        EnqueueEventTag153_021d079c(tag, 1, 0);
        return;
    }

    unsigned char cur2 = (unsigned char)GetSearchStructCurrentArrEntry((struct SearchStruct0202c1a4*)search);
    if (tag < cur2) {
        EnqueueEventTag153_021d079c(tag, 1, 1);
    } else {
        EnqueueEventTag153_021d079c(tag, 1, 0);
    }
}

#include <globaldefs.h>

extern "C" void* func_0202ae18(void);
extern "C" void* func_ov017_0218b5b0(void);
struct SearchStruct0202c1a4;
signed char GetSearchStructCurrentArrEntry(struct SearchStruct0202c1a4* obj);
struct BattleStruct;
struct BattleStruct* GetBattleStruct(void);
struct CombatantStruct;
struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
struct U16Field0x6_020375f8;
unsigned short GetU16At0x6(struct U16Field0x6_020375f8* obj);
void EnqueueEventTag154_021d0860(unsigned char a, unsigned char b, unsigned char c);

// USA: func_ov017_0219949c
extern "C" ARM void func_ov017_0219949c(void* ctx, int combatantId, int matchType, unsigned char slotId, signed char threshold) {
    struct SearchStruct0202c1a4* search = (struct SearchStruct0202c1a4*)func_0202ae18();
    signed char arrEntry = GetSearchStructCurrentArrEntry(search);

    if (matchType != arrEntry && matchType != 4) {
        return;
    }

    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantUnchecked(battle, combatantId);
    struct CombatantStruct* target = GetCombatantAtField0x397c(battle);
    unsigned short v1 = GetU16At0x6((struct U16Field0x6_020375f8*)combatant);
    unsigned short v2 = GetU16At0x6((struct U16Field0x6_020375f8*)target);

    if (v1 != v2) {
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }

    if (threshold != *(signed char*)((char*)ctx + 0x4447)) {
        func_ov017_0218b5b0();
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }

    unsigned char arrEntry2 = (unsigned char)GetSearchStructCurrentArrEntry(search);
    if (slotId < arrEntry2) {
        EnqueueEventTag154_021d0860(slotId, 1, 1);
        return;
    }
    EnqueueEventTag154_021d0860(slotId, 1, 0);
}

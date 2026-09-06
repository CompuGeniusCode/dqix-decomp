#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct FieldRefStruct_021d923c { void* field0; };

// USA: func_ov024_021d923c
ARM int ScaleAndStoreHP_021d923c(struct FieldRefStruct_021d923c* param1, int attackerId, int defenderId, int unused4, int unused5, int fallback) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* attacker = GetCombatantFromList(bs, attackerId);
    struct CombatantStruct* defender = GetCombatantFromList(bs, defenderId);
    if (attacker == NULL || defender == NULL) {
        return fallback;
    }
    int scaledAttackerHP = (int)((float)attacker->currentStats->primaryStats.currHP * 0.8f);
    *(int*)((char*)param1->field0 + 0x8e38) = scaledAttackerHP + 2;
    int scaledDefenderHP = (int)((float)defender->currentStats->primaryStats.currHP * 0.8f);
    return scaledDefenderHP;
}

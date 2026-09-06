#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021a2738
ARM struct CombatantStruct* FindCombatantByField2_021a2738(void* unused, int value) {
    if (value < 0) return NULL;
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    for (i = 0; i < 0xc; i++) {
        struct CombatantStruct* combatant = GetCombatantUnchecked(bs, i + 7);
        if (combatant) {
            if (value == *(short*)((char*)combatant + 0x2)) return combatant;
        }
    }
    return NULL;
}

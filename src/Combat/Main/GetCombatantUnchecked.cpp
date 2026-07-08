#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0200fd70
ARM struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId) {
    struct CombatantStruct* combatant;
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        combatant = 0;
    } else {
        combatant = battleStruct->combatantList[combatantId];
    }
    return combatant;
}

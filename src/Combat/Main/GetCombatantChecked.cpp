#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0200ff94
ARM struct CombatantStruct* GetCombatantChecked(struct BattleStruct* battleStruct, int combatantId) {
    struct CombatantStruct* combatant;
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        return 0;
    }
    combatant = battleStruct->combatantList[combatantId];
    if (combatant == 0) {
        return 0;
    }
    return combatant;
}

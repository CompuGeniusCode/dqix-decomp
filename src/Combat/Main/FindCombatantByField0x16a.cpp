#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0200ffe0
ARM struct CombatantStruct* FindCombatantByField0x16a(struct BattleStruct* battleStruct, int id) {
    struct CombatantStruct* combatant;
    int i;
    if (id < 0) {
        return 0;
    }
    for (i = 0x70; i <= 0x9f; i++) {
        combatant = battleStruct->combatantList[i];
        if (combatant != 0 && (combatant->flags & 0x20) && id == *(unsigned short*)((char*)combatant + 0x16a)) {
            return combatant;
        }
    }
    return 0;
}

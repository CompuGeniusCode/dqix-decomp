#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_0200fd48
ARM void ClearCombatantSlot(struct BattleStruct* battleStruct, int id) {
    battleStruct->combatantList[id] = NULL;
}

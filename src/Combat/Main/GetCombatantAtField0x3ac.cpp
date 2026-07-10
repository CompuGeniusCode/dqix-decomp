#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_0200fdcc
ARM struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct) {
    return GetCombatantUnchecked(battleStruct, *(int*)((char*)battleStruct + 0x3ac));
}

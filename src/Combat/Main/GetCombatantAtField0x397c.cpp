#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_0200fddc
ARM struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct) {
    return GetCombatantUnchecked(battleStruct, *(unsigned char*)((char*)battleStruct + 0x397c));
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov000_021536f8
ARM struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id) {
	return GetCombatantWithFlag0x400(GetBattleStruct(), id);
}

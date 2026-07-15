#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct*, int);

// USA: func_ov000_021536f8
ARM struct CombatantStruct* GetCombatantWithFlagov000_021536f8(int unused, int id) {
	return GetCombatantWithFlag0x400(GetBattleStruct(), id);
}

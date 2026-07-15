#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov004_0215f74c
ARM int HasCombatantWithFlag_0215f74c_0215f74c(int unused, int combatantId) {
	return GetCombatantWithFlag0x100(GetBattleStruct(), combatantId) != NULL;
}

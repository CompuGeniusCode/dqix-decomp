#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov003_02155f88
ARM int IsCombatantFlagit2Set_02155f88_02155f88(void* unused, int combatantId) {
	struct CombatantStruct* c = GetCombatantWithFlag0x800(GetBattleStruct(), combatantId);
	int result = 1;
	if (c != NULL) {
		int* p = *(int**)((char*)c + 0x130);
		result = (*p & 4) != 0;
	}
	return result;
}

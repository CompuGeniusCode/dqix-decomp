#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
unsigned short GetTableValue(void* obj);

// USA: func_ov003_02155ffc
ARM int IsTableValueNot99_02155ffc(void* unused, int combatantId) {
	struct CombatantStruct* c = GetCombatantWithFlag0x800(GetBattleStruct(), combatantId);
	int result = 0;
	if (c != NULL) {
		result = (GetTableValue(c) != 0x63);
	}
	return result;
}

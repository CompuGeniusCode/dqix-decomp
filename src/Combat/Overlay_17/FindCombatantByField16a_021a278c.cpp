#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x20(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021a278c
ARM struct CombatantStruct* FindCombatantByField16a_021a278c(void* unused, int val) {
	if (val <= 0) return NULL;
	struct BattleStruct* battle = GetBattleStruct();
	for (int i = 0; i < 0x30; i++) {
		struct CombatantStruct* c = GetCombatantWithFlag0x20(battle, i + 0x70);
		if (c) {
			unsigned short field16a = *(unsigned short*)((char*)c + 0x100 + 0x6a);
			if (val == field16a) return c;
		}
	}
	return NULL;
}

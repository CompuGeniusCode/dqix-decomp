#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400ByID(int unused, int id);

struct Wrapper_021f5c80 {
	int field0;
};

// USA: func_ov024_021f5c80
ARM int CheckAnyBuffBelow2_021f5c80(struct Wrapper_021f5c80* a, int id, int unused2, int* outFlag, short* outId) {
	struct CombatantStruct* c = GetCombatantWithFlag0x400ByID(a->field0, id);
	if (!c) return 0;
	int result;
	if (c->currentStats->attackBuff >= 2 && c->currentStats->defenseBuff >= 2 && c->currentStats->agilityBuff >= 2) {
		result = 0;
	} else {
		result = 1;
		*outFlag = result;
		*outId = (short)id;
	}
	return result;
}

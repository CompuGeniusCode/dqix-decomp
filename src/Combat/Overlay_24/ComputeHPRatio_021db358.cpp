#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021db358  (semantic: ComputeHPRatio_021db358)
extern "C" ARM float func_ov024_021db358(struct CombatantStruct* obj) {
	unsigned short currHP = obj->currentStats->primaryStats.currHP;
	if ((float)currHP == 0.0f) return 0.0f;
	unsigned short maxHP = obj->currentStats->primaryStats.maxHP;
	return (float)currHP / (float)maxHP;
}

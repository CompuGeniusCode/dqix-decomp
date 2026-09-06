#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

// USA: func_ov024_021d974c
ARM int RandomScaleMaxMP20to50Percent_021d974c(struct Random** rngPtr, int id, int a2, int a3, int a4, int val) {
	struct CombatantStruct* c = GetCombatantByID((int)*rngPtr, (short)id);
	if (!c) return val;
	unsigned short maxMP = c->currentStats->primaryStats.maxMP;
	struct Random* rng = *rngPtr;
	float f = NextRandomFloatBetween(rng, 0.2f, 0.5f);
	return (int)((float)maxMP * f);
}

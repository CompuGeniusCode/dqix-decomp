#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

struct RngHolder_021d9654 { struct Random* rng; };

// USA: func_ov024_021d9654  (semantic: RandomScaleAttackUnlessRandomMax2_021d9654)
extern "C" ARM int func_ov024_021d9654(struct RngHolder_021d9654* holder, int id, int a2, int a3, int a4, int fallback) {
	struct BattleStruct* bs = GetBattleStruct();
	struct CombatantStruct* combatant = GetCombatantFromList(bs, id);
	if (!combatant) return fallback;
	struct Random* rng = holder->rng;
	if (NextRandomMax(rng, 2) > 0) return 0;
	unsigned short atk = combatant->baseStats->primaryStats.attack;
	float f = NextRandomFloatBetween(rng, 0.95f, 1.05f);
	return (int)((float)atk * f);
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

// USA: func_ov024_021d8b68
ARM int RandomScaleAttack85to95Percent_021d8b68(struct Random** rngPtr, int id, int a2, int a3, int a4, int val) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, id);
    if (!c) return val;
    unsigned short atk = c->baseStats->primaryStats.attack;
    struct Random* rng = *rngPtr;
    float f = NextRandomFloatBetween(rng, 0.85f, 0.95f);
    return (int)((float)atk * f);
}

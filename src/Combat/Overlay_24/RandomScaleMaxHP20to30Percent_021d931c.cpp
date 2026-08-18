#include <globaldefs.h>
#include "Combat/Main/BattleList.h"
#include "Util/Random.h"

// USA: func_ov024_021d931c
ARM int RandomScaleMaxHP20to30Percent_021d931c(struct Random** rngPtr, int id, int a2, int a3, int a4, int val) {
    struct BattleStruct* bs = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantFromList(bs, id);
    if (!c) return val;
    unsigned short maxHp = c->currentStats->primaryStats.maxHP;
    struct Random* rng = *rngPtr;
    float f = NextRandomFloatBetween(rng, 0.2f, 0.3f);
    return (int)((float)maxHp * f);
}

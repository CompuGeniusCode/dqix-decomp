#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);

// USA: func_020dcc98  (semantic: ClassifyHPRatio020dcc98)
extern "C" ARM int func_020dcc98(int combatantId) {
    int result = 15;
    struct BattleStruct* battle = GetBattleStruct();
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battle, combatantId);
    if (c != 0) {
        float ratio;
        int maxHP = c->baseStats->primaryStats.maxHP;
        if ((float)maxHP == 0.0f) {
            ratio = 0.0f;
        } else {
            int* p = *(int**)((char*)c + 0x130);
            int cur = *(unsigned short*)((char*)p + 4);
            ratio = (float)cur / (float)maxHP;
        }

        if (ratio <= 0.25f) {
            result = 13;
        }
        if (ratio <= 0.08f) {
            result = 11;
        }
        if (ratio == 0.0f) {
            result = 9;
        }
    }
    return result;
}

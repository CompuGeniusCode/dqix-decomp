#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int func_02067fec(int, void*, int);

// USA: func_020689a4
ARM int TestFlag0x800CombatantWith02067fec(struct BattleStruct* battleStruct, int arg1, int arg2) {
    struct CombatantStruct* c = GetCombatantWithFlag0x800(battleStruct, 0);
    if (c != 0) {
        return func_02067fec(0, c->baseStats, arg2) == 0;
    }
    return 0;
}

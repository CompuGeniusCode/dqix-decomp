#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int func_02067f9c(int a, void* b, int c);

// USA: func_02068bf4
ARM int IsField0x3acStatCallZero(struct BattleStruct* battleStruct, int unused, int arg2) {
    struct CombatantStruct* combatant = GetCombatantAtField0x3ac(battleStruct);
    if (combatant != NULL) {
        return func_02067f9c(0, combatant->baseStats, arg2) == 0;
    }
    return 0;
}

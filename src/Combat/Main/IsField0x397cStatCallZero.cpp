#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" int func_02067f9c(int a, void* b, int c);

// USA: func_02068c30
ARM int IsField0x397cStatCallZero(struct BattleStruct* battleStruct, int unused, int arg2) {
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    if (combatant != NULL) {
        return func_02067f9c(0, combatant->baseStats, arg2) == 0;
    }
    return 0;
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x3ac(struct BattleStruct* battleStruct);
extern "C" int sprintf(int value, void* src);

// USA: func_0206918c
ARM void AccumulateField0x3acCombatantValue(void* unused, int* accum) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x3ac(battleStruct);
    void* stats;
    if (combatant == NULL) {
        return;
    }
    stats = *(void* volatile*)&combatant->baseStats;
    *accum += sprintf(*accum, stats);
}

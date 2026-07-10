#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantAtField0x397c(struct BattleStruct* battleStruct);
extern "C" int func_02003ce8(int value, void* src);

// USA: func_02069158
ARM void AccumulateField0x397cCombatantValue(void* unused, int* accum) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantAtField0x397c(battleStruct);
    void* stats;
    if (combatant == NULL) {
        return;
    }
    stats = *(void* volatile*)&combatant->baseStats;
    *accum += func_02003ce8(*accum, stats);
}

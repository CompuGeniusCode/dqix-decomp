#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId);
extern "C" int sprintf(int value, void* src);

// USA: func_02069120
ARM void AccumulateFlag0x800CombatantValue(void* unused, int* accum) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    struct CombatantStruct* combatant = GetCombatantWithFlag0x800(battleStruct, 0);
    void* stats;
    if (combatant == NULL) {
        return;
    }
    stats = *(void* volatile*)&combatant->baseStats;
    *accum += sprintf(*accum, stats);
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// The 0x1000 member of the combatant-lookup family: bounds-check, null-check, then require that
// bit of CombatantStruct::flags. What 0x1000 means is not established, so the bit stays in the
// name rather than being guessed at; func_02010038 in main gathers the same set.
// Callers are spread over ten modules and are led by ov017 gamemain (32 of 64 edges), so this is
// not a battle-only filter.
extern "C" ARM struct CombatantStruct* GetCombatantWithFlag0x1000(struct BattleStruct* battleStruct, int combatantId) {
    struct CombatantStruct* combatant;
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        return 0;
    }
    combatant = battleStruct->combatantList[combatantId];
    if (combatant == 0) {
        return 0;
    }
    if ((combatant->flags & 0x1000) == 0) {
        combatant = 0;
    }
    return combatant;
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Raw slot fetch: the id range is validated but nothing else, so an empty slot comes back as a
// null pointer. func_0200ff94 at 0x0200ff94 adds a null test that changes nothing, since it
// returns the same null; the eight 0x3c-byte siblings at 0x0200fd90 through 0x0200ff58 are this
// function plus one flag bit each.
extern "C" ARM struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId) {
    struct CombatantStruct* combatant;
    if (combatantId < 0) {
        return 0;
    }
    if (combatantId >= 0xE9) {
        combatant = 0;
    } else {
        combatant = battleStruct->combatantList[combatantId];
    }
    return combatant;
}

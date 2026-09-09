#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// One of nine byte-identical accessors over battleStruct->combatantList that return the combatant
// only when the halfword at its +0x0 has one particular bit set -- 0x2, 0x20, 0x80, 0x100, 0x200,
// 0x400, 0x800, 0x1000, and one that tests nothing. Only 0x800 is understood (func_020e455c walks
// ids 0..3 with it to reach the party); func_02076a8c sets 0x20 in a bulk init without saying what
// it means, so with 38 call sites the bit stays in the name rather than being guessed at.
extern "C" ARM struct CombatantStruct* GetCombatantWithFlag0x20(struct BattleStruct* battleStruct, int combatantId) {
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
    if ((combatant->flags & 0x20) == 0) {
        combatant = 0;
    }
    return combatant;
}

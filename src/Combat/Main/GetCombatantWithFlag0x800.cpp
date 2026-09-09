#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// One of eight byte-identical accessors over BattleStruct::combatantList that differ only in which
// flag bit they require; symbols.txt already carries most of the family, so the spelling is kept
// rather than invented (0x0200fe68, bit 0x80, is the odd one out as GetCombatantFromList). What
// bit 0x800 means is not established. Of the 304 call sites only 33 are in ov000 battle against
// 115 in ov017 gamemain, 38 in ov003 shisetsu and 28 in ov002 topmenu, fitting the note in
// include/Combat/Main/BattleList.h that BattleStruct reads as the global game-state root.
extern "C" ARM struct CombatantStruct* GetCombatantWithFlag0x800(struct BattleStruct* battleStruct, int combatantId) {
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
    if ((combatant->flags & 0x800) == 0) {
        combatant = 0;
    }
    return combatant;
}

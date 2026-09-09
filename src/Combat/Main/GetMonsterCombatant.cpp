#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Flag 0x400 marks a monster. func_02048614, which sets the flag, is a reset routine -- presumably
// the constructor -- that also clears the monster record pointers at +0x144/+0x148 and the name
// buffer at +0x14c, and func_020488ec fills that buffer with record+0x2c plus a suffix out of
// data_020f015c, the A/B/C letter the series appends when two of the same enemy are on screen.
// ov000 walks them as the eight ids 0xc0..0xc7. The flag lives on the combatant rather than on a
// battle record, so nothing here proves a monster outside a battle would not also carry it.
extern "C" ARM struct CombatantStruct* GetMonsterCombatant(struct BattleStruct* battleStruct, int combatantId) {
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
    if ((combatant->flags & 0x400) == 0) {
        combatant = 0;
    }
    return combatant;
}

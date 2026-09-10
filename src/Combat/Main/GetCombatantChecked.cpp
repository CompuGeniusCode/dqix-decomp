#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Bounds- and null-checked read of BattleStruct::combatantList. The 0xE9 limit is not independent
// evidence: BattleList.h declares the array that long with a "TODO: validate this size", and that
// declaration came from these very checks. The plain member of the family at 0x0200fd70 through
// 0x0200ff58 -- GetCombatantUnchecked skips the null test, the rest repeat these guards and then
// require flag bit 0x20, 0x80, 0x400 or 0x1000. Callers span ov000, ov002, ov003 and ov017 alike,
// fitting the header's warning that BattleStruct is misnamed and reaches at least 0x5722 bytes.
extern "C" ARM struct CombatantStruct* GetCombatantChecked(struct BattleStruct* battleStruct, int combatantId) {
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
    return combatant;
}

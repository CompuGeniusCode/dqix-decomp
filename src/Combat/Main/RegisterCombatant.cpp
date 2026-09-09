#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct SlotBackRef_fd38 {
    char pad[4];
    unsigned short id;
};

// Puts a combatant into slot id of the global combatant list and writes the id back into the
// combatant at +4, which is the handle everything else uses to find it again. ClearCombatantSlot
// next door is the removal, func_0200fd58 wipes all 0xe9 entries. No bounds check here, and
// only func_ov001_02160c78 range-checks the id before calling -- the other ov001 callers do not.
extern "C" ARM void RegisterCombatant(struct BattleStruct* battleStruct, int id, struct CombatantStruct* combatant) {
    battleStruct->combatantList[id] = combatant;
    ((struct SlotBackRef_fd38*)combatant)->id = id;
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Looks an entity up by id in the list on the global state root, returning it only when bit 0x100
// of its flags is set. It is one of nine near-identical accessors at 0x0200fd70-0x0200ff94 that
// differ only in the flag they demand, and 0x0200fea4, which demands 0x400, is accepted as
// GetMonsterCombatant, so the flags say what kind of entity a slot holds. Every decompiled caller
// dereferences the character record at +0x150 straight away, but QueueItembtlprmLoad null-checks
// GetCombatantRecord anyway, so 0x100 is not "has a record"; what it does mark is not established.
extern "C" ARM struct CombatantStruct* GetCombatantWithFlag0x100(struct BattleStruct* battleStruct, int combatantId) {
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
    if ((combatant->flags & 0x100) == 0) {
        combatant = 0;
    }
    return combatant;
}

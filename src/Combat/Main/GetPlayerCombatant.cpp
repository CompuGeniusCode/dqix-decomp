#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// The byte at +0x397c of the game state root selects a combatant, and this hands it back;
// presumably the character the player walks around as. func_0202445c copies its position into the
// camera object, func_02025f28 draws the minimap marker there with a per-id sprite,
// AtmosphericEffectSet::DetermineVisibilityFromUnknown gates the weather fade on it, and
// func_ov017_021bf6fc auto-walks it to a point. Whether the byte is a party slot rather than a
// plain combatant id is not established.
extern "C" ARM struct CombatantStruct* GetPlayerCombatant(struct BattleStruct* battleStruct) {
    return GetCombatantUnchecked(battleStruct, *(unsigned char*)((char*)battleStruct + 0x397c));
}

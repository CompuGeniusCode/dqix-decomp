#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Reads the byte at +0x397c of the global state root. It is an index into the actor list:
// GetPlayerCombatant, the sibling GetPlayerCombatant, passes exactly this byte to
// GetCombatantUnchecked, whose bound is 0xE9. Callers pair the actor it names with the camera --
// func_020daeb0 and func_020e455c mark +0x253 on it -- but whether it designates the player's
// character or whichever actor the camera follows is not established, and the strongest use,
// AtmosphericEffectSet::DetermineVisibilityFromUnknown fading weather on it, fits either reading.
extern "C" ARM unsigned char GetCombatantIdAtField0x397c(struct BattleStruct* battleStruct) {
    return *(unsigned char*)((char*)battleStruct + 0x397c);
}

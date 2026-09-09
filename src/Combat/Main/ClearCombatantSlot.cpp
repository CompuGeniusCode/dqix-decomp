#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Drops a combatant out of the game state root's combatant list by nulling its slot. Callers clear
// whole id ranges at once: ResetAndLoadMonModData clears 0x70..0x9f right before it reloads monster
// data, and two reset paths clear the sixteen slots at 0xd0..0xdf, so the argument is a fixed slot
// number rather than a handle. Unlike the neighbouring accessors at 0x0200fd70 and 0x0200fe68 this
// one does no bounds check, so an out-of-range id writes past the list. Nothing here releases the
// character data record the slot pointed at.
extern "C" ARM void ClearCombatantSlot(struct BattleStruct* battleStruct, int id) {
    battleStruct->combatantList[id] = NULL;
}

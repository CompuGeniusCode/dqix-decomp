#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Returns the combatant id at +0x3ac of the root GetBattleStruct returns: the character this
// console controls, 0 in single player and the local player's party slot in multiplayer. Of the
// four sites calling the setter at 0x020100a0, ov021 charamake and func_ov017_021c3a04 store 0
// while ov017's init and func_ov017_021b03b4 store func_0202c1a4(GetMultiplayerState()), the local
// slot index; nothing in ov000 battle writes it. GetMainCharacterCombatant hands the id to
// GetCombatantUnchecked, and func_020730e0 falls back to it when a caller passes a negative id.
extern "C" ARM int GetLocalPlayerCombatantId(struct BattleStruct* battleStruct) {
    return *(int*)((char*)battleStruct + 0x3ac);
}

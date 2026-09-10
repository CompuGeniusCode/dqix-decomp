#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

extern "C" struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// The int at +0x3ac of the game state root is the combatant id this passes to
// GetCombatantUnchecked. Only ov021 charamake and ov017 gamemain write it: three sites store 0 --
// the id whose name MatchesCipheredCombatantName_0206483c compares against the player's own -- and
// two store GetLocalPlayerId out of a 16-entry table, so the field is re-pointable
// rather than fixed on the hero. Grotto/TreasureMapMetadata.cpp reads that combatant's per-vocation
// levels, and routines taking an optional id fall back to it. There is no 0x100 flag check here.
extern "C" ARM struct CombatantStruct* GetMainCharacterCombatant(struct BattleStruct* battleStruct) {
    return GetCombatantUnchecked(battleStruct, *(int*)((char*)battleStruct + 0x3ac));
}

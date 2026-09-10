#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// Returns the player-owned block 0x2a04 into BattleStruct, which include/Combat/Main/BattleList.h
// already establishes as the global game state root. func_0207d2c4 clamps the word at +0xf6c to
// 0x98967f, the 9,999,999 gold cap; +0x1d4 and +0xe04 take keyed stack and count updates; +0xf78
// holds the party members' combatant ids and +0xf7c their count; and the seven bytes at +0x2c8d are
// the D-pad shortcut slots, memcpy'd whole by func_02039768 and picked one at a time by DS key bit
// in func_02037d88. Where the block ends is not established.
extern "C" ARM void* GetPlayerData(struct BattleStruct* battleStruct) {
    return (char*)battleStruct + 0x2a04;
}

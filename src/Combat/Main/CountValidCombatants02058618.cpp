#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_02058618
ARM int CountValidCombatants02058618() {
    struct BattleStruct* bs = GetBattleStruct();
    int count = 0;
    int i;
    for (i = 0; i < 0x10; i++) {
        if (GetCombatantUnchecked(bs, i + 0xd0)) {
            count++;
        }
    }
    return count;
}

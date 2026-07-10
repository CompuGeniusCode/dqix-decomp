#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_02026b7c
ARM void MarkActiveCombatantSlots02026b7c(unsigned char* obj) {
    struct BattleStruct* bs = GetBattleStruct();
    int i;
    obj += 0x96;
    for (i = 0; i < 4; i++) {
        if (GetCombatantUnchecked(bs, i)) {
            obj[0xa00] |= (1 << i);
        }
    }
}

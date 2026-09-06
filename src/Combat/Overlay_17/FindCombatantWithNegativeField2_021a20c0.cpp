#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);

// USA: func_ov017_021a20c0
ARM int FindCombatantWithNegativeField2_021a20c0(int unused, int mult, int limit) {
    struct BattleStruct* battleStruct = GetBattleStruct();
    if (limit > 0xc) limit = 0xc;
    int base = mult * 0xc;
    base = base + 0x70;
    for (int i = 0; i < limit; i++) {
        struct CombatantStruct* combatant = GetCombatantUnchecked(battleStruct, i + base);
        if (combatant != NULL) {
            short v = *(short*)((char*)combatant + 0x2);
            if (v < 0) return i + base;
        }
    }
    return -1;
}

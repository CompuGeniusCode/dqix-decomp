#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantUnchecked(struct BattleStruct* battleStruct, int combatantId);
int GetFieldMasked0x6c(void* obj, int mask);
extern "C" void func_02034d20(void* obj);

// USA: func_ov017_02197394
ARM void AdvanceCombatantsInRange_02197394(void) {
    struct BattleStruct* bs = GetBattleStruct();
    int id;
    for (id = 0xa0; id < 0xc0; id++) {
        struct CombatantStruct* combatant = GetCombatantUnchecked(bs, id);
        if (!combatant) continue;
        if (GetFieldMasked0x6c(combatant, 0x40000000) != 0) continue;
        func_02034d20(combatant);
    }
}

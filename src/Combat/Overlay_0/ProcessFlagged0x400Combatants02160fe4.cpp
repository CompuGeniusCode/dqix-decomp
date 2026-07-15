#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

struct CombatantStruct* GetCombatantWithFlag0x400(struct BattleStruct* battleStruct, int combatantId);
extern "C" void func_02048690(struct CombatantStruct* combatant);

// USA: func_ov000_02160fe4
ARM void ProcessFlagged0x400Combatants02160fe4(void) {
    struct BattleStruct* battle = GetBattleStruct();
    int i;
    for (i = 0; i < 8; i++) {
        struct CombatantStruct* c = GetCombatantWithFlag0x400(battle, i + 0xc0);
        if (c != 0) func_02048690(c);
    }
}

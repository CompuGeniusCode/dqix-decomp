#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov002_02154b94
ARM int HasPositiveField256Short178_02154b94(void* unused, int combatantId) {
    struct CombatantStruct* combatant = GetCombatantWithFlag0x100(GetBattleStruct(), combatantId);
    if (!combatant) {
        return 0;
    }
    int v = *(unsigned short*)((char*)combatant + 0x100 + 0xb2);
    if (v != 0) {
        return 1;
    }
    return 0;
}

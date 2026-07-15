#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021598a4
ARM int IsCombatantFlag0x20000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x20000000) != 0;
}

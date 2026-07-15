#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021598d4
ARM int IsCombatantFlag0x400000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x400000) != 0;
}

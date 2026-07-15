#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_021598bc
ARM int IsCombatantFlag0x4000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x4000000) != 0;
}

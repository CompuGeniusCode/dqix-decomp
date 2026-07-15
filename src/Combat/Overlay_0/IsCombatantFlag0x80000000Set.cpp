#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_02158324
ARM int IsCombatantFlag0x80000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x80000000) != 0;
}

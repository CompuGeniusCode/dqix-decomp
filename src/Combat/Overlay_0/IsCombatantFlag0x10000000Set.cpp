#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215988c
ARM int IsCombatantFlag0x10000000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x10000000) != 0;
}

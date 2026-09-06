#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215994c
ARM int IsCombatantFlag0x1000Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x1000) != 0;
}

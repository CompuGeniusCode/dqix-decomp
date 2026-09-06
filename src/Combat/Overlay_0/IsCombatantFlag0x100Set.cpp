#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov000_0215985c
ARM int IsCombatantFlag0x100Set(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x100) != 0;
}

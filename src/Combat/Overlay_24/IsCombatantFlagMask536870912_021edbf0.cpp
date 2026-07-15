#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021edbf0
ARM int IsCombatantFlagMask536870912_021edbf0(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x14) & 0x20000000) != 0;
}

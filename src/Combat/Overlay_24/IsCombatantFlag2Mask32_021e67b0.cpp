#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021e67b0
ARM int IsCombatantFlag2Mask32_021e67b0(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x20) != 0;
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021e6798
ARM int IsCombatantFlag2Mask8192_021e6798(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x2000) != 0;
}

#include <globaldefs.h>
#include "Combat/Main/BattleList.h"

// USA: func_ov024_021e7ba8
ARM int IsCombatantFlag2Mask2048_021e7ba8(struct CombatantStruct* combatant) {
    return (*(unsigned int*)((char*)combatant->currentStats + 0x18) & 0x800) != 0;
}
